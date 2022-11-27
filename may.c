#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

// This is linked list representation of different accounts. We can traverse the linked list until we match the specific username and then withdraw, 
// deposit or edit information about the account.

struct acc{
    int bal, phoneno,dob;
    char *name, *email,*username,*password;
    struct acc *next;
}*new,*head=NULL,*tail=NULL;

void create();
void delete();
void search();
void display();
void edit();
void admin(); 
void customer();
void withdraw();

void main(){
    printf("\n\n\t\t Welcome to banking management system \n");
    printf("\n\n\t\tPress any key to continue: ");
    getch();
    int option=1;
    
    
    while(option!=4){
        printf("\n\n\t\t Enter 1 for logging into admin login ");
            printf("\n\n\t\t Enter 2 for logging into customer login");
            printf("\n\n\t\t Enter 3 for logging into ATM service");
            printf("\n\n\t\t Enter 4 to exit\n");
            scanf("\t\t%d", &option);
        switch(option){
            
            case 1:admin();break;
            case 2:customer();break;
            case 3:withdraw();break;
            case 4:printf("Thank you for your services");break;
            default: printf("\n\n\t\t Enter a valid number");break;
        }
    }
}
void admin(){
    int option=1;
    while(option!=7){
            printf("\n\n\t\t 1. To create account");
            printf("\n\n\t\t 2. To delete account");
            printf("\n\n\t\t 3. To search account");
            printf("\n\n\t\t 4. To show list of accounts");
            printf("\n\n\t\t 5. To edit information");
            printf("\n\n\t\t 6. To go back to main menu");
            printf("\n\n\t\t 7. To exit\n");

            scanf("\t\t %d", &option);
        switch(option){
            // Creating account using create function which requires creating new node at the end of linked list.
            case 1:create();break;

            // Deleting a specific account with username in linked list. parameter as username needs to be passed.
            case 2:delete();break;

            // Searching a specific account with username in linked list and displaying all the user's information.
            case 3:search();break;

            // Displaying information about all the accounts in a systematic order.
            case 4:display();break;

            // edting specific information about a specific account.
            case 5:edit();break;
            case 6:printf("\n\n\t\t Going back to main menu");main();break;

            case 7:printf("\n\n\t\tThank you for using our services");
            exit(0);break;

            default:printf("Please enter valid number");
            
            break;


        }
    }

}
void create(){
    new = (struct acc *)malloc(sizeof(struct acc));
    printf("\n\n\t\tEnter your name: ");
        scanf("%s", &new->name);

        printf("\n\n\t\tEnter your phone number: ");
        scanf("%d", &new->phoneno);
        printf("\n\n\t\tEnter your date of birth: ");
        scanf("%d", &new->dob);


        printf("\n\n\t\tEnter your email: ");
        scanf("%s", &new->email);


        printf("\n\n\t\tEnter your user name: ");
        scanf("%s", &new->username);

        printf("\n\n\t\tEnter your password: ");
        scanf("%s", &new->password);

        printf("\n\n\t\tEnter your balance: ");
        scanf("%d", &new->bal);
new->next=NULL;
        
        
    if(head==NULL){
        head=new;
        tail=new;
       printf("\n\n\t\t You have succesfully created an account!!!!(head)");
        
    }
    else{
       

       tail->next = new;
            tail = new;
            printf("success");
    }
    
}
void search(){
    char username[15];
    printf("\n\n\t\t Enter username of account holder");
   scanf("%s",username);
    struct acc *temp=head;
    while(temp!=NULL){
        if(username==temp->username){
            printf("\n\n\t\tYour name is: %s", temp->name);

        printf("\n\n\t\t Your balance is: %d", temp->bal);

        printf("\n\n\t\t Your date of birth is :%d", temp->dob);


        printf("\n\n\t\t Your email is : %s", temp->email);

        printf("\n\n\t\tyour user name is: %s", temp->username);

        printf("\n\n\t\tYour phone number is: %s", temp->phoneno);
        

        }
        else temp=temp->next;
    }
}
void delete(){
    char username[15];

    printf("\n\n\t\tEnter username of account you wish to delete: ");
    gets(username);

    struct acc *temp=head;
    struct acc *prev=head;


    while(temp!=NULL){
        prev=temp;
        if(username==temp->username){
            prev->next=temp->next;
            temp->next=NULL;
            free(temp);
            exit(0);
        }
        else temp=temp->next;
    }
}

void edit(){
    char username[15];
    printf("\n\n\t\t Enter username whose account you wish to edit");
    gets(username);
    struct acc *temp =head;
    while(temp!=NULL){
        if(username==temp->username){
            char *name, *password,*email; 
            int dob,phoneno;

            int num;
  line4:
             printf("\n\n\t\t Enter 1. To edit name");
             printf("\n\n\t\t 2. To edit date of birth");
             printf("\n\n\t\t 3. To edit password");
             printf("\n\n\t\t 4. To edit email");
             printf("\n\n\t\t 5. To edit phone number");
             printf("\n\n\t\t 6. To exit");

            scanf("%d", &num);
            switch(num){
                case 1: 
                        
                        printf("\n\n\t\t Enter new name");
                        gets(name);
                        temp->name=name;break;
                case 2: 
                       
                        printf("\n\n\t\t Enter new date of birth");
                        scanf("%d", &dob);
                        temp->dob=dob;break;
                case 3:
                        
                        printf("\n\n\t\t Enter new passord");
                        gets(password);
                        temp->password=password;break;
                case 4:
                        printf("\n\n\t\t Enter new email");
                        gets(email);
                        temp->email=email;break;
                case 5:
      printf("\n\n\t\t Enter new phone number");
                        scanf("%d", &phoneno);
                        temp->phoneno=phoneno;break;
                case 6:printf("\n\n\t\t Thank you for using our services ");
                        main();break;
                default:printf("\n\n\t\t Enter valid number!!!!!!");
                goto line4;
            
            }

        }
        else temp=temp->next;
    }
    printf("\n\n\t\t Thank you for using our services ");

}

void display(){
    printf("\n\n\t\tDisplaying list of accounts and their information");
    struct acc *temp=head;
    printf("\n\n\t\t This is the list of all the accounts in our bank!!!!");

    while(temp!=NULL){
        printf("\n\n\t\t Yser name is: %s", temp->username);
        printf("\n\n\t\t name is: %s", temp->name);
        printf("\n\n\t\t  balance is: %d", temp->bal);
        printf("\n\n\t\t  date of birth is :%d", temp->dob);
        printf("\n\n\t\t  email is : %s", temp->email);
        printf("\n\n\t\t phone number is: %s", temp->phoneno);
        printf("\n\n\t\t ##############################");
        
        temp=temp->next;
    }
}

void customer(){
    int dep=0;
    int flag=0;
    struct acc *cur = head;
    char *user, *pass;
    

    printf("Enter Username");
    scanf("%s",&user);
    while(cur!=NULL){
        if(user==cur->username){
            flag=1;
            int num;
            line6:
            printf("Enter Password");
            scanf("%s",&pass);
            if(cur->password==pass){
                printf("\n\n\t\t %s",cur->name);
                printf("\n\n\t\t %s",cur->email);
                printf("\n\n\t\t %d",cur->phoneno);
                printf("\n\n\t\t %s",cur->dob);
                printf("\n\n\t\t %d",cur->bal);
                printf("\n\n\t\t Enter 1 if you want to deposit money and 0 if not");
                scanf("%d", &dep);
                switch(dep){
                    case 1:
                        
                        line5:
                        printf("\n\n\t\t Enter the amount of money you wish to deposit(* minimum 500rs*)");
                        scanf("%d", &num);
                        if(num>=500){
                            cur->bal+=num;
                        }
                        else {
                            printf("\n\n\t\t Enter larger number!!!!!!!!!");
                            goto line5;
                        }break;
                    case 0: break;
                    default:printf("\n\n\t\tEnter valid number !!!!!!!");
                    goto line5;break;
                }
            }
        } 
        else{
            printf("incorrect password");
            goto line6;
        }
    cur=cur->next;
    }

    if(flag==0){
        printf("username not found");
        
    }
}

void withdraw()
{int flag=0;
    struct acc *cur = head;
    int amount;
    char user[15], pass[15];
    printf("\n\n\t\t Enter Username");
    scanf("%s", &user);

    while (cur != NULL)
    {
        if (user == cur->username)
        {
            flag=1;
            printf("\n\n\t\t Enter password");
            scanf("%s", &pass);
            if (cur->password == pass)
            {
                printf("\n\n\t\t Enter amount you want to withdraw");
                scanf("%d", &amount);
                cur->bal = cur->bal - amount;
                printf("\n\n\t\t Amount %d withdrawn sucessfully", amount);
                printf("\n\n\t\t Current balane %d", cur->bal);
            }
            else
            {

                printf("\n\n\t\t Incorrect password");
            }
        }
        cur = cur->next;
    }

    if(flag==0){
        printf("\n\n\t\t Username not found");
    }
}

// void mainmenu(){
//     int choice;
//     lineno50:
//     printf("\n\t Main menu");
//     printf("\n\t 1. Account opening");
//     printf("\n\t 2. Details of account");
//     printf("\n\t 3. Update account");
//     printf("\n\t 4. Deposit");
//     printf("\n\t 5. Witdraw");
//     printf("\n\t 6. Update account");
//     scanf("%d", &choice);

//     switch(choice){
//         case 1:accOpen();
//                 goto lineno50;
//         break;
//         case 2:details();
//                 goto lineno50;
//         break;
//         case 3:update();
 //case 3:update();
//                 goto lineno50;
//         break;
//         case 4:deposit()
//                 goto lineno50;
//         ;break;
//         case 5:withdraw()
//                 goto lineno50;
//         ;break;
//         case 6: printf("\n\n\t Thanks for visiting ");
//         printf("\n\n\t\tPress any key to exit: ");
//         getch();
//         exit(0); break;
//         default:
//         printf("\n\n\t Enter a valid number...");

//         printf("\n\n\t Press any key to exit...");
//         getch();
//         goto lineno50;
//     }
// }
// !!!!!!!++++++++############## Please make ATM service after this line and do not delete this line ##############++++++++ !!!!!!!