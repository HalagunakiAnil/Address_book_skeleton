#include "contact.h"
#include<string.h>


void listContacts(AddressBook *addressBook) 
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("Name  :%s\n",addressBook->contacts[i].name);
        printf("Phone :%s\n",addressBook->contacts[i].phone);
        printf("Email :%s\n",addressBook->contacts[i].email);
        printf("\n");
    }
    
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    populate(addressBook);
    
}

void createContact(AddressBook *addressBook) 
{
    Contact *currentcontact = &addressBook->contacts[addressBook->contactCount];
    FILE *file;
    file = fopen("contacts.csv", "a");
    if (file == NULL)
    {
        printf("Error opening contacts.csv file!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]",currentcontact->name);
    getchar();

    //Phone
label:
        printf("Enter Phone number: ");
        scanf(" %s",currentcontact->phone);
        getchar();
        for(int i=0;i<addressBook->contactCount;i++)
        {
            int ret=strcmp(currentcontact->phone, addressBook->contacts[i].phone);
            if(ret==0)
            {
                printf("This contact already exists\n");
                goto label;
                break;
            }
        }
        char *current=currentcontact->phone;
        for(int i=0;i<current[i]!='\0';i++)
        {
            if(current[i]<'0' || current[i]>'9')
            {
                printf("please enter digits only\n");
                goto label;
                break;
            }
        }

        if(strlen(currentcontact->phone) !=10)
        {
            printf("please enter 10 digit mobile number\n");
            goto label;
        }

    //Email
label1:
        printf("Enter Email Id: ");
        scanf(" %s",currentcontact->email);
        getchar();
        for(int i=0;i<addressBook->contactCount;i++)
        {
            int ret=strcmp(currentcontact->email, addressBook->contacts[i].email);
            if(ret==0)
            {
                printf("This email already exists\n");
                goto label1;
                break;
            }
        }
        char *current_email=currentcontact->email;
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(current_email[i]>= 'A' && current_email[i]<='Z')
            {
                printf("please enter lowercase characters only\n");
                goto label1;
                break;
            }
        }

        char *str1 = strstr(currentcontact->email, "@");
        char *str2 = strstr(currentcontact->email, ".com");

    if (*currentcontact->email == '@')
    {
        printf("Email cannot start with @\n");
        goto label1;
    }
        if (!str1 || !str2)
        {
            printf("Enter a valid email id\n");
            goto label1;
        }

    fprintf(file, "Name: %s,Phone: %s,Email: %s\n", currentcontact->name, currentcontact->phone, currentcontact->email);
    fclose(file);
    addressBook->contactCount++;

}

void searchContact(AddressBook *addressBook) 
{
    int choice;
    char str[50];
    int flag=0;

    printf("Search by\n 1.Name \n 2.Phone \n 3.Email\nEnter choice: ");
    scanf("%d", &choice);
    label2:
    if(choice == 1)
    {
      while(!flag)
      {
        printf("Enter Name: ");
        scanf(" %[^\n]", str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            int ret = strcmp(addressBook->contacts[i].name,str);

            if(ret == 0)
            {
                printf("\n<-- Details Below -->\n");
                printf("Name: %s\n",addressBook->contacts[i].name);
                printf("Phone:%s\n",addressBook->contacts[i].phone);
                printf("Email:%s\n",addressBook->contacts[i].email);
                printf("\n");
                flag=1;
                break;
            }
        }
                if(!flag)
                {
                  printf("Please enter a valid name.\n");
                  goto label2;
                }
      }
    }
    if(choice == 2)
    {
      while(!flag)
      {
        printf("Enter Phone:");
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            int ret = strcmp(addressBook->contacts[i].phone,str);
            if(ret == 0)
            {
                printf("\n<-- Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n",addressBook->contacts[i].phone);
                printf("Email: %s\n",addressBook->contacts[i].email);
                printf("\n");
                flag =1;
                break;
            }
        }
          if(!flag)
            {
              printf("Please enter a valid Phone Number.\n");
              goto label2;
            }
      }
    }
    if(choice == 3)
    {
      while(!flag)
      {
        printf("Enter Email:");
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            int ret = strcmp(addressBook->contacts[i].email,str);

            if(ret == 0)
            {
                printf("\n<-- Details Below -->\n");
                printf("Name: %s\n",addressBook->contacts[i].name);
                printf("Phone :%s\n",addressBook->contacts[i].phone);
                printf("Email: %s\n",addressBook->contacts[i].email);
                printf("\n");
                flag = 1;
                break;
            }
        }
            if(!flag)
            {
                printf("Please enter a valid Email Id.\n");
                goto label2;
            }
        
      }
    }
}

void editContact(AddressBook *addressBook) 
{
  int choice;
  char str[50];
  int flag = 1;
  int found =0;
  printf("Edit by\n1.Name\n2.Phone\n3.Email\nEnter Choice: ");
  scanf("%d",&choice);
  if(choice == 1)
  {
     printf("Edit Name: ");
     scanf(" %[^\n]",str);

     for(int i=0;i<addressBook->contactCount;i++)
     {
      if(strcmp(addressBook->contacts[i].name,str) == 0)
      {
          found = 1;
          printf("Do you want to edit\n1.Name\n2.Phone\n3.Email\nEnter Choice:");
          scanf("%d",&choice);


         if(choice ==1)
         { 
          printf("Enter new name: ");
          scanf(" %[^\n]",addressBook->contacts[i].name);
         }
          if(choice == 2)
         {
           printf("Enter new Phone: ");
           scanf("%s",addressBook->contacts[i].phone);
          }
         if(choice == 3)
         {
           printf("Enter new Email: ");
           scanf("%s",addressBook->contacts[i].email);
          }
        }
     }
   }
 if(choice == 2)
  {
    printf("Enter a edit phone: ");
    scanf("%s",str);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,str)==0)
        {
            found = 1;
            printf("Do you want to edit\n1.Name\n2.Phone\n3.Email\nEnter choice: ");
            scanf("%d",&choice);

            if(choice ==1)
           { 
           printf("Enter new name: ");
           scanf(" %[^\n]",addressBook->contacts[i].name);
           }
          if(choice == 2)
          {
           printf("Enter new Phone: ");
           scanf("%s",addressBook->contacts[i].phone);
          }
          if(choice == 3)
          {
           printf("Enter new Email: ");
           scanf("%s",addressBook->contacts[i].email);
          }
        }
    }

  }
  if(choice ==3)
  {
    printf("Enter edit email: ");
    scanf("%s",str);

  }
}

void deleteContact(AddressBook *addressBook) 
{

}
