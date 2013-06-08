#ifndef MAPFILE_H
#define MAPFILE_H

#include <Windows.h>
#include <QString>

#define MAXSYMBOLNAME 64
#define MAXMODULENAME 64
#define ADDRESS_MASK 0x01FFFFFF

typedef struct
{
    int address;
    int length;
    char name[MAXSYMBOLNAME];
    char module[MAXMODULENAME];
} MAPSYMBOL, *PMAPSYMBOL;

class MapFile
{
public:
    MapFile(const QString &fileName = QString());
    ~MapFile();
    bool isValid() const;
    bool load(const QString &fileName);
    PMAPSYMBOL lookupSymbol(int address);

protected:

private:
    QString m_fileName;
    int m_symbolCount;
    PMAPSYMBOL m_symbolTable;
};

#endif // MAPFILE_H
