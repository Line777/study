typedef unsigned int Index;
typedef Index Positon;
struct HashTbl;
typedef struct HashTbl *HashTable;
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int key,HashTable H);
void Insert(int key,HashTable H);
int Retrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);
enum KindOfEntry{Legitimate,Empty,Deleted};
struct HanshEntry
{
    int data;
    enum KindOfEntry Info;
};
typedef struct HashEntry Cell;
struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};
HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;
    if(TableSize<MinTableSize)
    {
        return NULL;

    }
    H=malloc(sizeof(structHashTbl));
    if(H==NULL)
    {
        printf("OUt of Space");
    }
    H->TableSize=NextPrime(TableSize);
    H->TheCells=malloc(sizeof(Cell)*H->TableSize);
    if(H->TheCells==NULL)
    printf("out of space");
    for(i=0;i<H->TableSize;i++)
    {
        H->TheCells[i].info=Empty;

    }
    return H;
}
Position Find(int key,HashTable H)
{
    Position CurrentPos;
    int CollisionNum;
    CollisionNum=0;
    CurrentPos=Hash(key,H->TableSize);
    while(H->TheCells[CurrentPos].info!=Empty&&H->TheCells[CurrentPos].data!=key)
    {
        CurrentPos+=2*++CollisionNum-1;
        if(CurrentPos>=H->TableSize)
          CurrentPos-=H->TableSize;
    }
    return CurrentPos;
}
void Insert(int key,HashTable H)
{
    Position Pos;
    Pos=Find(key,H);
    if(H->TheCells[Pos].info!=Legitimate)
    {
        H->TheCells[Pos].info=Legitimate;
        H->TheCells[Pos].data=key;
    }
}
