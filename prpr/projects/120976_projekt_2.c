#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Values
{
    float Latitude, Longtitude, Value;
} Values;

typedef struct Id
{
    char Label, Kind;
    int Numbering;
} Id;

typedef struct module
{
    Id *IdDescription;
    char Hour[3], Minute[3];
    Values *RecordValues;
    char Date[9], Type[3];
    struct module *Next;
} MODULE_INFORMATION;

struct module *swap(struct module *PointerOne, struct module *PointerTwo)
{
    MODULE_INFORMATION *Temp = PointerTwo->Next;
    PointerTwo->Next = PointerOne;
    PointerOne->Next = Temp;
    return PointerTwo;
}

void dealocate(MODULE_INFORMATION **Head)
{
    MODULE_INFORMATION *Temp = *Head, *Following;
    while (Temp != NULL)
    {
        Following = Temp->Next;
        if (Temp->IdDescription != NULL)
            free(Temp->IdDescription);
        Temp->IdDescription = NULL;
        // Check and free RecordValues
        if (Temp->RecordValues != NULL)
            free(Temp->RecordValues);
        Temp->RecordValues = NULL;
        // Free the node itself
        free(Temp);
        Temp = Following;
    }
    (*Head) = NULL;
}

void WritePosition(Values **Head, char String[30])
{
    int IndexCount = 0, TemporaryIndex = 0, MainIndex = 0;
    char Titude[20];

    while (String[MainIndex] != '\0')
    {
        MainIndex = IndexCount + TemporaryIndex;
        Titude[IndexCount] = String[MainIndex];
        if (String[MainIndex + 1] == '+' || String[MainIndex + 1] == '-')
        {
            Titude[IndexCount + 1] = '\0';
            (*Head)->Latitude = atof(Titude);
            TemporaryIndex = IndexCount;
            IndexCount = 0;
        }
        IndexCount++;
    }
    memmove(Titude, Titude + 1, strlen(Titude));
    Titude[IndexCount + 1] = '\0';
    (*Head)->Longtitude = atof(Titude);
}

void WriteTime(MODULE_INFORMATION **Head, char String[30])
{
    (*Head)->Hour[0] = String[0];
    (*Head)->Hour[1] = String[1];
    (*Head)->Hour[2] = '\0';
    (*Head)->Minute[0] = String[2];
    (*Head)->Minute[1] = String[3];
    (*Head)->Minute[2] = '\0';
}

void n(MODULE_INFORMATION **Head, int *count)
{
    int line = 0;
    char String[30], TextNumbering[3];
    FILE *file;
    file = fopen("dataloger_V2.txt", "r");
    if (*Head != NULL)
    {
        dealocate(Head);
        *count = 0;
    }

    if (file == NULL)
        printf("Zaznamy neboli nacitane!\n");
    else
    {
        MODULE_INFORMATION *NewStruct, *Last, *Temp;
        NewStruct = malloc(sizeof(MODULE_INFORMATION));
        NewStruct->IdDescription = NULL;
        NewStruct->RecordValues = NULL;
        while (fgets(String, 30, file) != NULL)
        {
            String[strcspn(String, "\r\n")] = '\0';
            switch (line)
            {

            case 1:
                NewStruct = malloc(sizeof(MODULE_INFORMATION));
                NewStruct->IdDescription = malloc(sizeof(Id));

                // Writing Id to sub-struct
                NewStruct->IdDescription->Label = String[0];
                for (int i = 1; i < 4; i++)
                {
                    TextNumbering[i - 1] = String[i];
                }
                NewStruct->IdDescription->Numbering = atoi(TextNumbering);
                NewStruct->IdDescription->Kind = String[4];
                break;
            case 2:
                NewStruct->RecordValues = malloc(sizeof(Values));

                // Rewrites Longtitude and Latitude to NewStruct->RecordValues
                WritePosition(&(NewStruct->RecordValues), String);
                break;
            case 3:
                strcpy(NewStruct->Type, String);
                break;
            case 4:
                NewStruct->RecordValues->Value = atof(String);
                break;
            case 5:
                // Writes Hour and Minutes to NewStruct
                WriteTime(&NewStruct, String);
                break;
            case 6:
                strcpy(NewStruct->Date, String);

                NewStruct->Next = NULL;
                if ((*Head) == NULL)
                {
                    (*Head) = NewStruct;
                }
                else
                {
                    Last = *Head;
                    while (Last->Next != NULL)
                    {
                        Last = Last->Next;
                    }
                    Last->Next = NewStruct;
                }
                NewStruct = NewStruct->Next;
                (*count)++;
                line = -1;
                break;
            }

            line++;
        }
        printf("Nacitalo sa %d zaznamov\n", (*count));
        fclose(file);
        free(NewStruct);
    }
}

int v(MODULE_INFORMATION **Head, int *Count)
{
    if ((*Head) == NULL)
        return 0;

    MODULE_INFORMATION *Temp = (*Head);
    int Index = 1;
    Id *CurrentId;
    Values *CurrentValues;
    int CanContinue = 1;
    for (int i = 0; i < (*Count); i++)
    {
        // Pointers to sub structs
        CurrentId = Temp->IdDescription;
        CurrentValues = Temp->RecordValues;

        // For +/- there are ternar operators
        printf("%d:\nID: %c%d%c\t%s\t%.2f\nPoz: %c%.4f\t%c%.4f\nDaC: %s\t%s%s\n",
               Index, CurrentId->Label, CurrentId->Numbering, CurrentId->Kind, Temp->Type,
               CurrentValues->Value,
               CurrentValues->Latitude > 0 ? '+' : '\0', CurrentValues->Latitude,
               CurrentValues->Longtitude > 0 ? '+' : '\0', CurrentValues->Longtitude,
               Temp->Date, Temp->Hour, Temp->Minute);
        // :)

        if (Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Index++;
    }
}

void p(MODULE_INFORMATION **Head, int *TotalCount)
{
    MODULE_INFORMATION *Temp = *Head, *NewStruct;
    NewStruct = malloc(sizeof(MODULE_INFORMATION));
    NewStruct->RecordValues = malloc(sizeof(Values));
    NewStruct->IdDescription = malloc(sizeof(Id));

    Id *NewId = NewStruct->IdDescription;
    int Input, Count = 1, NewNumbering;
    char NewPosition[30], NewTime[30];
    float NewValue;

    scanf(" %d", &Input);
    // Scans whole input
    scanf(" %c%d%c\n %s\n %s\n %f\n %s\n %s",
          &NewId->Label, &NewId->Numbering, &NewId->Kind,
          NewPosition, NewStruct->Type, &NewStruct->RecordValues->Value,
          NewTime, NewStruct->Date);

    NewPosition[strcspn(NewPosition, "\r\n")] = '\0';
    NewTime[strcspn(NewTime, "\r\n")] = '\0';
    WriteTime(&NewStruct, NewTime);
    WritePosition(&(NewStruct->RecordValues), NewPosition);

    if (*Head == NULL)
    {
        // Case when Head is empty
        NewStruct->Next = NULL;
        *Head = malloc(sizeof(MODULE_INFORMATION));
        (*Head)->RecordValues = malloc(sizeof(Values));
        (*Head)->IdDescription = malloc(sizeof(Id));

        *Head = NewStruct;
    }
    else if (Input == 1)
    {
        // Case of input infront of linked list
        NewStruct->Next = Temp;
        *Head = NewStruct;
    }
    else if (Input <= 0 || Input > *TotalCount)
    {
        // Case where Input is out of range
        while (Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }

        Temp->Next = NewStruct;
        NewStruct->Next = NULL;
    }
    else
    {
        // Case when input is in range
        while ((Count + 1) != Input)
        {
            Count++;
            Temp = Temp->Next;
        }

        NewStruct->Next = Temp->Next;
        Temp->Next = NewStruct;
    }
    (*TotalCount)++;
}

int z(MODULE_INFORMATION **Head, int *TotalCount)
{
    char SearchLabel, SearchKind;
    int SearchNumbering, Count = 0;
    scanf(" %c%d%c", &SearchLabel, &SearchNumbering, &SearchKind);
    // No need for comparing records
    if (*Head == NULL)
        return 0;

    MODULE_INFORMATION *Temp = *Head, *Previous = NULL;
    Id *CompareId;
    while (Temp->Next != NULL)
    {
        CompareId = Temp->IdDescription;
        if (SearchLabel == CompareId->Label && SearchNumbering == CompareId->Numbering && SearchKind == CompareId->Kind)
        {
            printf("Zaznam pre ID: %c%d%c bol vymazany.\n", CompareId->Label, CompareId->Numbering, CompareId->Kind);
            free(Temp->IdDescription);
            free(Temp->RecordValues);
            Count++;
            if (Previous == NULL)
            {
                (*Head) = Temp->Next;
                free(Temp);
                Temp = (*Head);
            }
            else
            {
                Previous->Next = Temp->Next;
                free(Temp);
                Temp = Previous->Next;
            }
        }
        else
        {
            Previous = Temp;
            Temp = Temp->Next;
        }
    }
    (*TotalCount) -= Count;
}

// Returns to variable recalculated date
void RecalculateDate(MODULE_INFORMATION *Head, int *Year, int *Days, int *Minutes)
{
    char Variable[6]; // :)
    for (int i = 0; i < 4; i++)
    {
        Variable[i] = (Head)->Date[i];
    }
    Variable[4] = '\0';
    (*Year) = atoi(Variable);

    // Recalculating month to days
    Variable[0] = (Head)->Date[4];
    Variable[1] = (Head)->Date[5];
    Variable[2] = '\0';
    (*Days) = atoi(Variable) * 30;
    // Count of months to days
    Variable[0] = (Head)->Date[6];
    Variable[1] = (Head)->Date[7];
    (*Days) += atoi(Variable);
    // Recalculating Hours to minutes
    Variable[0] = (Head)->Hour[0];
    Variable[1] = (Head)->Hour[1];
    (*Minutes) = atoi(Variable) * 60;
    // Count to minutes
    Variable[0] = (Head)->Hour[2];
    Variable[1] = (Head)->Hour[3];
    (*Minutes) += atoi(Variable);
}

int r(MODULE_INFORMATION **Head, int Count)
{
    int PositionOne, PositionTwo, Index = 1;
    scanf(" %d %d", &PositionOne, &PositionTwo);

    if (PositionOne > PositionTwo)
    {
        int TemporaryPosition = PositionOne;
        PositionOne = PositionTwo;
        PositionTwo = TemporaryPosition;
    }

    if (PositionOne > Count || PositionTwo > Count || PositionOne <= 0 || PositionTwo <= 0 || PositionOne == PositionTwo)
        return 0;

    MODULE_INFORMATION *Temp = (*Head), *PreviousOne = NULL, *PreviousTwo = NULL, *NodeOne = NULL, *NodeTwo = NULL, *TempPrevious = NULL;
    while (Temp != NULL)
    {
        if (Index == PositionOne)
        {
            PreviousOne = TempPrevious;
            NodeOne = Temp;
        }

        if (Index == PositionTwo)
        {
            PreviousTwo = TempPrevious;
            NodeTwo = Temp;
        }
        TempPrevious = Temp;
        Temp = Temp->Next;
        Index++;
    }

    if (NodeOne == NULL || NodeTwo == NULL)
        return 0;

    if (PreviousOne != NULL)
        PreviousOne->Next = NodeTwo;
    else
        (*Head) = NodeTwo;
    

    if (PreviousTwo != NULL)
        PreviousTwo->Next = NodeOne;
    else
        (*Head) = NodeOne;


    if (NodeOne->Next == NodeTwo)
    {
        NodeOne->Next = NodeTwo->Next;
        NodeTwo->Next = NodeOne;
    }
    else
    {
        Temp = NodeOne->Next;
        NodeOne->Next = NodeTwo->Next;
        NodeTwo->Next = Temp;
    }
}

// Used algorithm from website https://www.geeksforgeeks.org/sorting-a-singly-linked-list/
int u(MODULE_INFORMATION **Head, int Count)
{
    MODULE_INFORMATION **SecondHead, *PointerOne, *PointerTwo;
    int NewStructCount = 0, FirstYear, FirstDays, FirstMinutes, SecondYear, SecondDays, SecondMinutes, ChangeSmallest = 0, Swapped = 0;

    for (int i = 0; i <= Count; i++)
    {

        SecondHead = Head;

        for (int j = 0; j < Count - i - 1; j++)
        {

            PointerOne = *SecondHead;
            PointerTwo = PointerOne->Next;
            RecalculateDate(PointerOne, &SecondYear, &SecondDays, &SecondMinutes);
            RecalculateDate(PointerTwo, &FirstYear, &FirstDays, &FirstMinutes);
            if (FirstYear < SecondYear)
            {
                ChangeSmallest = 1; // Changes Smallest based on year
            }
            else if (FirstYear == SecondYear)
            {
                if (FirstDays < SecondDays)
                {
                    ChangeSmallest = 1; // Changes Smallest based on day
                }
                else if (FirstDays == SecondDays)
                {
                    if (FirstMinutes < SecondMinutes)
                    {
                        ChangeSmallest = 1; // Changes Smallest based on minutes
                    }
                }
            }

            if (ChangeSmallest == 1)
            {

                /* update the link after swapping */
                *SecondHead = swap(PointerOne, PointerTwo);
                Swapped = 1;
                ChangeSmallest = 0;
            }

            SecondHead = &(*SecondHead)->Next;
        }

        /* break if the loop ended without any swap */
        if (Swapped == 0)
            break;
    }

    printf("Spajany zoznam bol usporiadany\n");
}

void k(MODULE_INFORMATION **Head, int *TotalCount, int *ContinueIndex)
{
    if (*Head != NULL)
        dealocate(Head);

    (*TotalCount) = 0;
    (*ContinueIndex) = 0;
}

int main(int argc, char const *argv[])
{
    char c;
    MODULE_INFORMATION *Head = NULL;
    MODULE_INFORMATION *temp = Head;
    int TotalCounts = 0, CanContinue = 1;
    while (CanContinue)
    {
        scanf(" %c", &c);
        switch (c)
        {
        case 'v':
            v(&Head, &TotalCounts);
            break;
        case 'n':
            n(&Head, &TotalCounts);
            break;
        case 'p':
            p(&Head, &TotalCounts);
            break;
        case 'z':
            z(&Head, &TotalCounts);
            break;
        case 'u':
            u(&Head, TotalCounts);
            break;
        case 'r':
            r(&Head, TotalCounts);
            break;
        case 'k':
            k(&Head, &TotalCounts, &CanContinue);
            break;
        default:
            break;
        }
    }

    return 0;
}