//channel: Prajapati Brothers(https://www.youtube.com/channel/UC4ODI9mfNUy34hj1AJ64IZQ)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char word[20],meaning[100];
    struct node*left,*right;
};
struct node* head;
FILE *fp1;
struct node* SearchANode(struct node* temp,char data[20]);
//make a new node
struct node*createNewNode(char word[20],char meaning[100])
{
        struct node*temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->word,word);
        strcpy(temp->meaning,meaning);
        temp->left = NULL;
        temp->right = NULL;
        return temp;
}
//COMPARE STRING
int cmpString(char a[20],char b[20])
{
    int i;
    for(i=0;i<20;i++)
    {
        if(a[i] == b[i]) continue;
        return (a[i] > b[i])?1:-1;
    }
    return 0;
}
//Insert a node
 struct node*Insert(struct node*temp1,char data[20],char meaning[100])
{
   if(temp1 == NULL)
    { // empty tree

		temp1 = createNewNode(data,meaning);
    }
	// if data to be inserted is lesser, insert in left subtree.
	else if(strcasecmp(data,temp1->word) == -1)
    {

		temp1->left = Insert(temp1->left,data,meaning);
	}
	// else, insert in right subtree.
	else if(strcasecmp(data,temp1->word)== 1)
    {
		temp1->right = Insert(temp1->right,data,meaning);
	}
	//sizeOfTree++;
	return temp1;
}
//Inorder Display
void inDisplay(struct node*temp)
{
    if(temp==NULL) return;
    else
        {
            inDisplay(temp->left);
            printf("\n%s\n",temp->word);
            inDisplay(temp->right);
        }
}

//===================================MiN NODE OF TREE
struct node* returnMinNode(struct node*temp)
{
    do
    {
        temp = temp->left;
    }while(temp->left != NULL);

    return temp;
};
//==================================delete a value from tree.
struct node* Delete(struct node *temp, char data[20])
{
	if(temp == NULL) return NULL;
	else if(strcasecmp(data,temp->word) == -1)
    {
        temp->left = Delete(temp->left,data);
    }
	else if (strcasecmp(data,temp->word) == 1)
    {
             head->right = Delete(temp->right,data);
    }
	else
    {
		// Case 1:  No child
		if(temp->left == NULL && temp->right == NULL)
		{
			free(temp);
			temp = NULL;
		}
		//Case 2: One child
		else if(temp->left == NULL)
		{
			struct node *temp1 = temp;
            temp = temp->right;
			free(temp1);
		}
		else if(temp->right == NULL)
		{
			struct node *temp1 = temp;
			temp = temp->left;
			 free(temp1);
		}
		// case 3: 2 children
		else
        {
			struct node *temp1 = returnMinNode(temp->right);
			int i;
			for(i=0;i<20;i++)
			temp->word[i] = temp1->word[i];
			temp->right = Delete(temp->right,temp1->word);
		}
	}
	return temp;
}
//write in the given file
void writeInFile(char word[20],char meaning[256])
{
    fp1 = fopen("C:\\Dhruv\\coding\\DSAsign\\dictonary\\first.txt","a");
    fprintf(fp1,"\n~%s`%s",word,meaning);
    //fprintf(fp1,"\n");
    fclose(fp1);
}

//remove character from string.
void removeChar(char *str, char garbage)
{

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++)
    {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

//open a dictionary
void openDictonery()
{
    //open the file which contain the Whole dictionary
    fp1 = fopen("C:\\Dhruv\\coding\\DSAsign\\dictonary\\first.txt","r");
    char word[20],meaning[256];
    char st[384],data[384];
    char ch;
    int i =0;

    while((ch = fgetc(fp1)) != EOF )
       {
           if(ch=='~')
            {
                fscanf(fp1,"%[^\n]%*c",data);
               //printf("\n%s",data);
                strcpy(st,data);
                char *ch1;
                ch1 = strtok(st, "`");
                while (ch1 != NULL)
                {
                    if(i == 0)
                    {
                        strcpy(word,ch1);
                        ch1 = "";
                    }

                    else
                    {
                        strcpy(meaning,ch1);
                        ch1 = "";
                    }
                    i++;
                    ch1 = strtok(NULL, "`");
                }

                //Insert the data scan from file to Input.
                removeChar(word,'~');
                removeChar(meaning,'~');
                //printf(" %s %s \n",word,meaning);
                head = Insert(head,word,meaning);
                i=0;
            }

        }
}
//=====================================Serch
struct node* SerchANode(struct node*temp,char data[20])
{
    //Search word in BST
    //if not exist then return NULL pointer.
	if(head == NULL)
    {
		return NULL;
    }
    //otherwise return pointer to that node in BST
	else if(temp->word == data)
	{
		return temp;
	}
	else if(strcasecmp(data,temp->word) == -1)
	{
		temp = SerchANode(temp->left,data);
	}
	else if(strcasecmp(data,temp->word) == 1)
	{
		temp = SerchANode(temp->right,data);
	}
	return temp;
};
//=============Display child of node
void childOfNode(struct node*temp)
{
    inDisplay(temp);
}
//this Function display all the word which have given substring
void allSubStringContainInDictonery(struct node*temp1,char search[20])
{
    //primary concept BFS--{ Breadth first Search }
    if(temp1 == NULL) return;
    enqueue(temp1);

    while(isEmpty() != 1)
    {
        if(peek() > 0)
            {
            struct node*temp = peek();

            //if subString is in word it will display it.
            if(checkSubString(temp->word,search) == 1)
            {
                printf(" %s ",temp->word);
            }

            if(temp->left != NULL)
            {
                enqueue(temp->left);
            }
            if(temp->right != NULL)
            {
                enqueue(temp->right);
            }
            dequeue();
            }
    }
}
//check if substring is in string or not
int checkSubString(char *sent,char *word)
{
    int flag = 0;
    //if not contain return null pointer to "check".
    char *check = strstr(sent, word);
    if(check)
        flag = 1;
    return flag;

}
//main of nDictionary
int main()
{
    head = NULL;
    int x=99;
    char ch2 = ' ';
    char word[20],meaning[256];
    struct node*temp;

    printf("\n DICTIONARY. \n");

    printf("\n Retrieving Data from Old Dictionary. \n");
    printf("\n ... \n");
    openDictonery();
    printf("\n Please Wait \n");
    printf("\n ... \n");
    printf("\n Data Retrieved from Old Dictionary. \n");
    while(x!=0)
    {
        printf(" \n 0. Exit \n 1. Insert. \n 2. Know the Meaning of Word. \n 3. Display Whole Dictionary. \n 4. Know Similar word. \n");
        printf(" Input choice:-");
        scanf("%d",&x);

        switch(x)
        {
            case 1: printf("\nInput word:-");
                    scanf("%s",word);
                    printf("\nInput meaning:-");
                    scanf("\n");
                    scanf("%[^\n]%*c",meaning);
                    head = Insert(head,word,meaning);
                    writeInFile(word,meaning);
                    break;

            case 2: printf("\nInput name:-");
                    scanf("%s",word);
                    temp = SerchANode(head,word);
                    if(temp==NULL)
                        printf("%s is not Exist.\n",word);
                    else
                        printf("\n Meaning of the word %s is %s\n",temp->word,temp->meaning);
                    break;

            case 3: inDisplay(head);
                    break;

            case 4: printf("\nInput name:-");
                    scanf("%s",word);
                    printf("\nSimilar word to %s are :-");
                    allSubStringContainInDictonery(head,word);
                    printf("\n");
                    break;

            case 9: printf("Input name:-");
                    scanf("%s",word);
                    if((head = Delete(head,word))==NULL)
                    printf("%s is not Exist.",word);
                    break;

            case 0: break;

            default:printf("\n Invalid Input, Please try again. \n");
                    continue;
        }
    }
    printf("\n Thank You \n");
    printf("\n DICTIONARY Ends.\n");

    return 0;
}

//==========================================queue
struct elm
{
    int data1;
    struct elm*next;
};
struct elm* front = NULL;
struct elm* rear = NULL;

struct elm* makeELement(int data1)
{
    struct elm* temp = (struct elm*)malloc(sizeof(struct elm));
    temp->data1 = data1;
    temp->next = NULL;
    return temp;
}

int isEmpty()
    {
        return (front == NULL && rear == NULL)?1:0;
    }
void enqueue(int data1)
{
    struct elm*temp = makeELement(data1);
    if(front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct elm*temp = front;
    if(front == NULL)
    {
        return;
    }
    else if(front == rear)
    {
      front = NULL;
      rear = NULL;
      free(temp);
      return;
    }
    else
    {
        front = front->next;
        free(temp);
    }
}
int peek()
{
    if(front == NULL) return -1;
    else return front->data1;
}

