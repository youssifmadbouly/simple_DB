#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10
        int counter=0;
        struct students
        {
            int ID;
            int Year;
            int courseID[3];
            int coursegrade[3];
        }student[10];
        bool SDB_AddEntry(int ID ,int year,int *subjects, int *grades)
        {
            int i;
        if(counter > MaxSize)
        {
            return 0;
        }
        else
        {
            student[counter].ID=ID;
            student[counter].Year=year;
             for(i=0;i<3;i++)
             {
              student[counter].courseID[i]=subjects[i];
              student[counter].coursegrade[i]=grades[i];

             }
            counter++;
            printf("Number of entries is = %d\n",counter);
        return 1;
        }
        }
        int SDB_GetUsedSize(void)
        {
            return counter;
        }
        bool SDB_ISFULL(void)
        {
                if(counter==MaxSize)
                {
                    return 1;
                }
                else
                return 0;
        }
        void SDB_DeletEntry(int ID)
        {
            int i;
            for(i=0;i<MaxSize;i++)
           {
                if(ID==student[i].ID)
                {
                    for(i=i+1;i<MaxSize-1;i++)
                    {
                    student[i-1]=student[i];
                    }
                    counter--;
                    printf("The entry is deleted successfully  is\n");
                    printf("Number of Entries is %d \n",counter);
                }
            }
        }
        bool SDB_ReadEntry(int ID ,int *year,int *subjects, int *grades)
        {
            int i;
            int j;
            for(i=0;i<MaxSize;i++)
            {
                if(ID==student[i].ID)
                {
                    year=student[i].Year;
                    subjects=student[i].courseID;
                    grades=student[i].coursegrade;
                    printf("ID is %d\n",ID);
                    printf("Year is %d\n",year);
                    for(j=0;j<3;j++)
                    {
                        printf("course %d ID is %d \n",j+1,subjects[j]);
                        printf("course %d GRADE is %d \n",j+1,grades[j]);
                    }
                    return 1;
                }
            }
                    return 0;

        }
        void SDB_GetIdList(int*counter,int*list)
        {
            int i;
            for(i=0;i<counter;i++)
            {
                printf("Student %d ID is %d \n",i+1,student[i].ID);
            }
            printf("Number of student %d \n",counter);
        }
        bool SDB_IsIdExist(int ID)
        {
            int i;
            for(i=0;i<MaxSize;i++)
            {
                if(ID==(student[i].ID))
                {
                        return 1;
                }
            }
                        return 0;
        }
        int main()
        {
        int ID=0;
        int Year;
        int input=0;
        int i;
        int x;
        int coursegrade[3];
        int courseid[3];
        int *year;
        label:
        printf("press 1 to check if the database is full or not \npress 2 to get the number of entries in the database\npress 3 to add new entry\npress 4 to delete entry\npress 5 to get ID list\npress 6 to search for an ID\nPress 7 to Read an Entry\n");
        printf("You Entered \t");
        scanf("%d",&input);
        printf("\n");
            if(input == 1) //SDB is full
            {
                printf("%d\n",SDB_ISFULL());
                printf("Please enter 10 to return to main menu and any other character to end the program\n");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else if(input == 2) //number of entries
            {
                printf("number of entries is %d\n",SDB_GetUsedSize());
                printf("Please enter 10 return to main menu and any other character to end the program\n");
                scanf("%d",&input);
                if(input == 10)
                {
                    goto label;
                }
                else goto label2;
            }
            else if(input == 3) //add new entry
            {
                printf("Please enter ID \t");
                scanf("%d",&ID);
                printf("Please enter Year \t");
                scanf("%d",&Year);
                for(i=0;i<3;i++)
                {
                    printf("Add course %d ID \t",i+1);
                    scanf("%d",&courseid[i]);
                    printf("course %d grade  \t",i+1);
                    scanf("%d",&coursegrade[i]);
                    while (coursegrade[i]<0 || coursegrade[i]>100)
                    {
                      printf("invalid input , please enter your grade again from 0 to 100\n");
                      scanf("%d",&coursegrade[i]);
                    }
                }
                x=SDB_AddEntry(ID,Year,courseid,coursegrade);
               if(x==1)
               {
                   printf("Added successfully\n");
                   printf("Please enter 10 to return to main menu and any other character to end the program\n");
                   scanf("%d",&input);
                    if(input == 10)
                    {
                            goto label;
                    }
                    else goto label2;
               }
               else
                   printf("Failed\n");
                   printf("Please enter 10 to return to main menu and any other character to end the program\n");
                   scanf("%d",&input);

                    if(input == 10)
                    {
                            goto label;
                    }
            }
            else if(input == 4) //delete an entry
            {
                printf("Enter the ID to delete Entry \t");
                scanf("%d",&ID);
                SDB_DeletEntry(ID);
                printf("Please enter 10 return to main menu and any other character to end the program \t");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else if(input == 5) //get id list
            {
                SDB_GetIdList(counter,&ID);
                printf("Please enter 10 return to main menu and any other character to end the program \t");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else if(input == 6) //is id exist
            {
                printf("Enter ID \t");
                scanf("%d",&ID);
                x=SDB_IsIdExist(ID);
                if(x==1)
                {
                    printf("ID IS EXIST\n");
                    printf("Please enter 10 return to main menu and any other character to end the program \t");
                    scanf("%d",&input);
                    if(input == 10)
                    {
                            goto label;
                    }
                    else goto label2;
                }
                else
                {
                    printf("NOT FOUND\n");
                    printf("Please enter 10 return to main menu and any other character to end the program \t");
                    scanf("%d",&input);
                    if(input == 10)
                    {
                            goto label;
          #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10
        int counter=0;
        struct students
        {
            int ID;
            int Year;
            int courseID[3];
            int coursegrade[3];
        }student[10];
        bool SDB_AddEntry(int ID ,int year,int *subjects, int *grades)
        {
            int i;
        if(counter > MaxSize)
        {
            return 0;
        }
        else
        {
            student[counter].ID=ID;
            student[counter].Year=year;
             for(i=0;i<3;i++)
             {
              student[counter].courseID[i]=subjects[i];
              student[counter].coursegrade[i]=grades[i];

             }
            counter++;
            printf("Number of entries is = %d\n",counter);
        return 1;
        }
        }
        int SDB_GetUsedSize(void)
        {
            return counter;
        }
        bool SDB_ISFULL(void)
        {
                if(counter==MaxSize)
                {
                    return 1;
                }
                else
                return 0;
        }
        void SDB_DeletEntry(int ID)
        {
            int i;
            for(i=0;i<MaxSize;i++)
           {
                if(ID==student[i].ID)
                {
                    for(i=i+1;i<MaxSize-1;i++)
                    {
                    student[i-1]=student[i];
                    }
                    counter--;
                    printf("The entry is deleted successfully  is\n");
                    printf("Number of Entries is %d \n",counter);
                }
            }
        }
        bool SDB_ReadEntry(int ID ,int *year,int *subjects, int *grades)
        {
            int i;
            int j;
            for(i=0;i<MaxSize;i++)
            {
                if(ID==student[i].ID)
                {
                    year=student[i].Year;
                    subjects=student[i].courseID;
                    grades=student[i].coursegrade;
                    printf("ID is %d\n",ID);
                    printf("Year is %d\n",year);
                    for(j=0;j<3;j++)
                    {
                        printf("course %d ID is %d \n",j+1,subjects[j]);
                        printf("course %d GRADE is %d \n",j+1,grades[j]);
                    }
                    return 1;
                }
            }
                    return 0;

        }
        void SDB_GetIdList(int*counter,int*list)
        {
            int i;
            for(i=0;i<counter;i++)
            {
                printf("Student %d ID is %d \n",i+1,student[i].ID);
            }
            printf("Number of student %d \n",counter);
        }
        bool SDB_IsIdExist(int ID)
        {
            int i;
            for(i=0;i<MaxSize;i++)
            {
                if(ID==(student[i].ID))
                {
                        return 1;
                }
            }
                        return 0;
        }
        int main()
        {
        int ID=0;
        int Year;
        int input=0;
        int i;
        int x;
        int coursegrade[3];
        int courseid[3];
        int *year;
        label:
        printf("press 1 to check if the database is full or not \npress 2 to get the number of entries in the database\npress 3 to add new entry\npress 4 to delete entry\npress 5 to get ID list\npress 6 to search for an ID\nPress 7 to Read an Entry\n");
        printf("You Entered \t");
        scanf("%d",&input);
        printf("\n");
            if(input == 1) //SDB is full
            {
                printf("%d\n",SDB_ISFULL());
                printf("Please enter 10 to return to main menu and any other character to end the program\n");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else if(input == 2) //number of entries
            {
                printf("number of entries is %d\n",SDB_GetUsedSize());
                printf("Please enter 10 return to main menu and any other character to end the program\n");
                scanf("%d",&input);
                if(input == 10)
                {
                    goto label;
                }
                else goto label2;
            }
            else if(input == 3) //add new entry
            {
                printf("Please enter ID \t");
                scanf("%d",&ID);
                printf("Please enter Year \t");
                scanf("%d",&Year);
                for(i=0;i<3;i++)
                {
                    printf("Add course %d ID \t",i+1);
                    scanf("%d",&courseid[i]);
                    printf("course %d grade  \t",i+1);
                    scanf("%d",&coursegrade[i]);
                    while (coursegrade[i]<0 || coursegrade[i]>100)
                    {
                      printf("invalid input , please enter your grade again from 0 to 100\n");
                      scanf("%d",&coursegrade[i]);
                    }
                }
                x=SDB_AddEntry(ID,Year,courseid,coursegrade);
               if(x==1)
               {
                   printf("Added successfully\n");
                   printf("Please enter 10 to return to main menu and any other character to end the program\n");
                   scanf("%d",&input);
                    if(input == 10)
                    {
                            goto label;
                    }
                    else goto label2;
               }
               else
                   printf("Failed\n");
                   printf("Please enter 10 to return to main menu and any other character to end the program\n");
                   scanf("%d",&input);

                    if(input == 10)
                    {
                            goto label;
                    }
            }
            else if(input == 4) //delete an entry
            {
                printf("Enter the ID to delete Entry \t");
                scanf("%d",&ID);
                SDB_DeletEntry(ID);
                printf("Please enter 10 return to main menu and any other character to end the program \t");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else if(input == 5) //get id list
            {
                SDB_GetIdList(counter,&ID);
                printf("Please enter 10 return to main menu and any other character to end the program \t");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else if(input == 6) //is id exist
            {
                printf("Enter ID \t");
                scanf("%d",&ID);
                x=SDB_IsIdExist(ID);
                if(x==1)
                {
                    printf("ID IS EXIST\n");
                    printf("Please enter 10 return to main menu and any other character to end the program \t");
                    scanf("%d",&input);
                    if(input == 10)
                    {
                            goto label;
                    }
                    else goto label2;
                }
                else
                {
                    printf("NOT FOUND\n");
                    printf("Please enter 10 return to main menu and any other character to end the program \t");
                    scanf("%d",&input);
                    if(input == 10)
                    {
                            goto label;
                    }
                    else goto label2;
                }
            }
            else if(input==7) //ReadEntry
            {
                printf("Please Enter ID to print its data \t");
                scanf("%d",&ID);
                x=SDB_ReadEntry(ID,year,courseid,coursegrade);
                if(x==1)
                {
                    printf("Entry Exists\n");
                }

                else
                printf("Entry does not exist\n");

                printf("Please enter 10 return to main menu and any other character to end the program \t");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else
            {
                printf("please enter a valid input\t");
                goto label;
            }
            label2:
        return 0;
    }
          }
                    else goto label2;
                }
            }
            else if(input==7) //ReadEntry
            {
                printf("Please Enter ID to print its data \t");
                scanf("%d",&ID);
                x=SDB_ReadEntry(ID,year,courseid,coursegrade);
                if(x==1)
                {
                    printf("Entry Exists\n");
                }

                else
                printf("Entry does not exist\n");

                printf("Please enter 10 return to main menu and any other character to end the program \t");
                scanf("%d",&input);
                if(input == 10)
                {
                        goto label;
                }
                else goto label2;
            }
            else
            {
                printf("please enter a valid input\t");
                goto label;
            }
            label2:
        return 0;
    }
