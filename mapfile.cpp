#include <QtCore>
#include "mapfile.h"

//
// Compare an address against an element of the symbol table.
// If the address is less than the symbol table element start, return -1.
// If the address falls in the range for the symbol table element, return 0.
// Otherwise return 1.
//
int compareAddress(const int key, const PMAPSYMBOL pSymbol)
{
    if (key < pSymbol->address)
        return -1;
    else if (key <= pSymbol->address + pSymbol->length - 1)
        return 0;
    else
        return 1;
}

// Binary search support function
PMAPSYMBOL bsearch(
        const int key,
        const PMAPSYMBOL base,
        size_t      num,
        int ( __cdecl *compare ) ( const int, const PMAPSYMBOL)
       )
{
    PMAPSYMBOL pResult = NULL;
    int dwLower, dwUpper, dwMiddle;
    int compareResult;
    PMAPSYMBOL pMiddleArrayElement;
    if (num == 0)
        return NULL;
    dwLower = 0;
    dwUpper = num - 1;
    while (dwLower <= dwUpper)
    {
        // Bisect [dwLower..dwUpper] with dwMiddle
        dwMiddle = dwLower + (dwUpper - dwLower) / 2;
        pMiddleArrayElement = base + dwMiddle;
        compareResult = compare(key, pMiddleArrayElement);
        if (compareResult == 0)
        {
            // Match found, return it.
            pResult = pMiddleArrayElement;
            break;
        }
        else if (compareResult < 0)
        {
            // key is less than pCurArrayElement, so dwMiddle - 1
            // is our new upper bound
            if (dwMiddle == 0)
                break;
            dwUpper = dwMiddle - 1;
        }
        else
        {
            // key is greater than pCurArrayElement, so dwMiddle + 1
            // is our new lower bound
            dwLower = dwMiddle + 1;
        }
    }
    return pResult;
}

MapFile::MapFile(const QString &fileName)
    : m_symbolCount(0)
    , m_symbolTable(NULL)
{
    load(fileName);
}

MapFile::~MapFile()
{
    delete m_symbolTable;
}

bool MapFile::isValid() const
{
    return (m_symbolTable != NULL && m_symbolCount > 0);
}

bool MapFile::load(const QString &fileName)
{
    int count;
    QFile file(fileName);
    if (!file.exists())
        return false;

    if (file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);
        QBuffer buffer;
        QString line;
         do {
             line = in.readLine();
             line = line.trimmed();
             if (line.startsWith("Address"))
             {
                 break;
             }
         } while (!line.isNull());

         if (buffer.open(QIODevice::ReadWrite))
         {
             QTextStream stream(&buffer);
             count = 0;
             do {
                 line = in.readLine();
                 if (line.isEmpty())
                 {
                     continue;
                 }
                 line = line.simplified();
                 if (line.startsWith("entry point at"))
                 {
                     break;
                 }
                 else if (line.section(" ", 3, 3) != "f")
                 {
                     continue;
                 }

                 stream << line << endl;
                 count++;
             } while (!line.isNull());

             if (0 != count)
             {
                 if (NULL != m_symbolTable)
                 {
                     delete m_symbolTable;
                     m_symbolTable = NULL;
                 }

                 m_fileName = fileName;
                 const int size = sizeof(MAPSYMBOL) * count;
                 m_symbolTable = (PMAPSYMBOL)new qint8[size];
                 memset(m_symbolTable, 0, size);
                 m_symbolCount = count;
                 MAPSYMBOL *pCurrSymbol = m_symbolTable;
                 MAPSYMBOL *pPrevSymbol = NULL;
                 stream.seek(0);
                 while (!stream.atEnd()) {
                     line = stream.readLine();
                     qstrcpy(pCurrSymbol->name, line.section(" ", 1, 1).toStdString().c_str());
                     pCurrSymbol->address = line.section(" ", 2, 2).toUInt(NULL, 16);
                     pCurrSymbol->length = 0;
                     QString module = line.section(" ", 4);
                     if (module.startsWith("i "))
                     {
                         module = module.mid(2);
                     }
                     qstrcpy(pCurrSymbol->module, module.toStdString().c_str());
                     //qDebug("%08x %s\n", pCurrSymbol->address, pCurrSymbol->name);
                     if (NULL != pPrevSymbol && 0 == pPrevSymbol->length)
                     {
                         pPrevSymbol->length = pCurrSymbol->address - pPrevSymbol->address;
                     }
                     pPrevSymbol = pCurrSymbol;
                     pCurrSymbol++;
                 };
             }
         }
     }

    return true;
}

PMAPSYMBOL MapFile::lookupSymbol(int address)
{
    if (NULL != m_symbolTable && m_symbolCount > 0)
    {
        //bsearch(&address, m_symbolCount, sizeof(MAPSYMBOL), compareAddress)
        PMAPSYMBOL pSymbol = (PMAPSYMBOL) bsearch(address,
                        m_symbolTable,
                        m_symbolCount,
                        compareAddress);

        return pSymbol;
    }

    return NULL;
}

