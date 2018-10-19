/*
@Discription: Library Management System
@Composer: Julius Song
@Date of Commencement: 04/25/2017
@Date of Completion: 04/29/2017
@Last Revised @ 05/01/2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Date{
	int year,month,day;
};

struct BookItem{
	char title[100],author[100],type;
	struct Date date;//Date of Purchase
	float price;
	int index;//Index Number 
	BookItem *next;
};//Each Book Item has Six Fields: Title, Author, Date of Purchase, Price, Type, and Index Number, with One Linking Pointer Field *next

void Traverse(BookItem *&h){
	BookItem *p=h->next;//Input Head Node
	printf("Title	Author	Date of Purchase	Price	Type	Index Number\n");//Print Title of Output Chart
	while(p){
		printf("%s	%s	%d/%02d/%02d		%.2f	%c	%d\n",p->title,p->author,p->date.year,p->date.month,p->date.day,p->price,p->type,p->index);
		p=p->next;
	}
}//Function 2: Traverse (Also Used in Function 1: Add & Function 4: Sort)

void Show(BookItem *&p){
	printf("Title	Author	Date of Purchase	Price	Type	Index Number\n%s	%s	%d/%02d/%02d		%.2f	%c	%d\n",p->title,p->author,p->date.year,p->date.month,p->date.day,p->price,p->type,p->index);
}//Show Information of a Certain Item. (Used in Function 5: Delete & Function 6: Revise)

void Add(BookItem *&h){
	BookItem *p=h,*q,*t;int i;
	while(p->next) p=p->next;//p is End of the Existed Link List, and Head of the Link List to be Added
	t=p;
	printf("#Add Book Items#\nPlease Input Information of the Books to Be Added in Following Order:\nTitle, Author, Date of Purchase, Price, Type(A,B,C), Index Number.\nExample:Davinci_Code Dan_Brown 2017 04 25 50.05 A 23\n\n");
	printf("**Space Should be Replaced by \"_\", Part Each Field with One Space.\n**Index Number is the Unique Identification of Each Book Item, Hence It Cannot be Revised, and Should Not be Distributed to More Than One Item.\n\n");
	do{
		q=(BookItem*)malloc(sizeof(BookItem));//Allocate Memory for Item to be Added
		scanf("%s%s%d%d%d%f %c%d",q->title,q->author,&q->date.year,&q->date.month,&q->date.day,&q->price,&q->type,&q->index);//Input Information of the Item to Be Added
		t->next=q,q->next=NULL,t=q;//Link Added Node to the End of Link List
		printf("Input \"1\" to Continue Adding, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Adding. All Inputs Are Valid, and At Least Input Once
	printf("\nYou Have Successfully Added the Book Item(s) Listed Below:\n");
	Traverse(p);//Show Adding Result
}//Function 1: Add

void Search(BookItem *&h){
	int i;BookItem *p;
	printf("#Search Book Items#\n");
	do{
		int op,n=0,f=0;BookItem *result[100]={};//n is the Number of Results, Maximum Searching Results are 100
		char key_title[100],key_author[100],key_type;int key_index;Date key_date;
		printf("\nWhat Field does the Searching Keyword Belong To? Please Input a Number:\n");
		printf("1:Title   2:Author   3:Type   4:Index Number   5:Date of Purchase\n");
		scanf("%d",&op);
		p=h->next;//Start Searching
		switch(op){
			case 1:
				printf("Pleas Input the Title You Want to Search:\n");
				scanf("%s",key_title);
				while(p){
					if(!strcmp(p->title,key_title)) result[n++]=p;
					p=p->next;
				}
				break;//Option 1: Search for Title
			case 2:
				printf("Pleas Input the Author You Want to Search:\n");
				scanf("%s",key_author);
				while(p){
					if(!strcmp(p->author,key_author)) result[n++]=p;
					p=p->next;
				}
				break;//Option 2: Search for Author
			case 3:
				printf("Pleas Input the Type You Want to Search:\n");
				scanf("\n%c",&key_type);
				while(p){
					if(p->type==key_type) result[n++]=p;
					p=p->next;
				}
				break;//Option 3: Search for Type
			case 4:
				printf("Pleas Input the Index Number You Want to Search:\n");
				scanf("%d",&key_index);
				while(p){
					if(p->index==key_index) result[n++]=p;
					p=p->next;
				}
				break;//Option 4: Search for Index Number
			case 5:
				printf("Pleas Input the Date of Purchase You Want to Search, Eg: 2017 04 25:\n");
				scanf("%d%d%d",&key_date.year,&key_date.month,&key_date.day);
				while(p){
					if(p->date.year==key_date.year&&p->date.month==key_date.month&&p->date.day==key_date.day) result[n++]=p;
					p=p->next;
				}
				break;//Option 5: Search for Date of Purchase
			default:
				printf("Input Error!\n");f++;
		}//Search for Key Field
		if(!n&&!f) printf("There is No Matching Item!\n");//Matching Failed
		else if(n){
			printf("\nMatching Result(s) with Keyword: ");
			switch(op){
				case 1:
					printf("Title = %s",key_title);
					break;//With Title
				case 2:
					printf("Author = %s",key_author);
					break;//With Author
				case 3:
					printf("Type = %c",key_type);
					break;//With Type
				case 4:
					printf("Index Number = %d",key_index);
					break;//With Index Number
				case 5:
					printf("Date of Purchase = %d/%d/%d",key_date.year,key_date.month,key_date.day);
					break;//With Date of Purchase
			}//Field of Keyword Searched With. (No Need for Default)
			printf(" are:\nTitle	Author	Date of Purchase	Price	Type	Index Number\n");
			for(int j=0;j<n;j++) printf("%s	%s	%d/%02d/%02d		%.2f	%c	%d\n",result[j]->title,result[j]->author,result[j]->date.year,result[j]->date.month,result[j]->date.day,result[j]->price,result[j]->type,result[j]->index); 
		}//Searching Succeeded
		printf("\nInput \"1\" to Continue Searching, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Searching
}//Function 3: Search

void Swap(BookItem *&a,BookItem *&b){
	BookItem *t;
	t=(BookItem*)malloc(sizeof(BookItem));
	strcpy(t->title,a->title);strcpy(t->author,a->author);t->date=a->date,t->price=a->price,t->type=a->type,t->index=a->index;
	strcpy(a->title,b->title);strcpy(a->author,b->author);a->date=b->date,a->price=b->price,a->type=b->type,a->index=b->index;
	strcpy(b->title,t->title);strcpy(b->author,t->author);b->date=t->date,b->price=t->price,b->type=t->type,b->index=t->index;
}//Swap Information Stored in Node *a & *b. (Used in Function 3: Sort)

void Sort(BookItem *&h){
	BookItem *p,*t,*max,*min;int i,op,order;
	printf("#Sort Book Items#\n");
	do{
		printf("\nWith Which Field Do You Intend to Sort? Please Input a Number:\n");
		printf("1:Title   2:Author   3:Date of Purchase   4:Price   5:Type   6:Index Number\n");
		scanf("%d",&op);
		printf("In Which Order Do You Prefer to Sort? Please Input a Number:\n");
		printf("1: Ascending Order	2: Descending Order\n");
		scanf("%d",&order);
		if((op<1||op>6)||(order!=1&&order!=2)) printf("Input Error!\n");//Illegal Input
		else{
			switch(op){
				case 1:
					if(order==1){
						for(p=h->next;p;p=p->next){
							for(min=p,t=p->next;t;t=t->next)
								if(strcmp(t->title,min->title)<0) min=t;
							if(min!=p) Swap(min,p);
						}//Simple Selection Sort
					}//AscOrd
					else{
						for(p=h->next;p;p=p->next){
							for(max=p,t=p->next;t;t=t->next)
								if(strcmp(t->title,max->title)>0) max=t;
							if(max!=p) Swap(max,p);
						}//Simple Selection Sort
					}//DesOrd
					break;//Option 1: Sort with Title
				case 2:
					if(order==1){
						for(p=h->next;p;p=p->next){
							for(min=p,t=p->next;t;t=t->next)
								if(strcmp(t->author,min->author)<0) min=t;
							if(min!=p) Swap(min,p);
						}//Simple Selection Sort
					}//AscOrd
					else{
						for(p=h->next;p;p=p->next){
							for(max=p,t=p->next;t;t=t->next)
								if(strcmp(t->author,max->author)>0) max=t;
							if(max!=p) Swap(max,p);
						}//Simple Selection Sort
					}//DesOrd
					break;//Option 2: Sort with Author
				case 3:
					BookItem *y,*m;
					if(order==1){
						for(p=h->next;p;p=p->next){
							for(min=p,t=p->next;t;t=t->next)
								if(t->date.year<min->date.year) min=t;
							if(min!=p) Swap(min,p);
						}//Sort Year, Simple Selection Sort
						for(p=h->next;p;p=y->next){
							for(y=p;y->next&&y->next->date.year==p->date.year;y=y->next);//y Points to the Last Node that Has the Same Year with p
							while(p!=y){
								for(min=p,t=p->next;t!=y->next;t=t->next)
									if(t->date.month<min->date.month) min=t;
								if(min!=p) Swap(min,p);
								p=p->next;
							}//Simple Selection Sort
						}//Sort Month in Each Year, with Partition of Year
						for(p=h->next;p;p=y->next){
							for(y=p;y->next&&y->next->date.year==p->date.year;y=y->next);//Partition of Year
							for(;p;p=m->next){
								for(m=p;m->next&&m->next->date.month==p->date.month;m=m->next);//m Points to the Last Node that Has the Same Month (and Year) with p
								while(p!=m){
									for(min=p,t=p->next;t!=m->next;t=t->next)
										if(t->date.day<min->date.day) min=t;
									if(min!=p) Swap(min,p);
									p=p->next;
								}//Simple Selection Sort
							}//Sort Day in Each Month, with Partition of Month
						}
					}//AscOrd
					else{
						for(p=h->next;p;p=p->next){
							for(max=p,t=p->next;t;t=t->next)
								if(t->date.year>max->date.year) max=t;
							if(max!=p) Swap(max,p);
						}//Sort Year, Simple Selection Sort
						for(p=h->next;p;p=y->next){
							for(y=p;y->next&&y->next->date.year==p->date.year;y=y->next);//y Points to the Last Node that Has the Same Year with p
							while(p!=y){
								for(max=p,t=p->next;t!=y->next;t=t->next)
									if(t->date.month>max->date.month) max=t;
								if(max!=p) Swap(max,p);
								p=p->next;
							}//Simple Selection Sort
						}//Sort Month in Each Year, with Partition of Year
						for(p=h->next;p;p=y->next){
							for(y=p;y->next&&y->next->date.year==p->date.year;y=y->next);//Partition of Year
							for(;p;p=m->next){
								for(m=p;m->next&&m->next->date.month==p->date.month;m=m->next);//m Points to the Last Node that Has the Same Month (and Year) with p
								while(p!=m){
									for(max=p,t=p->next;t!=m->next;t=t->next)
										if(t->date.day>max->date.day) max=t;
									if(max!=p) Swap(max,p);
									p=p->next;
								}//Simple Selection Sort
							}//Sort Day in Each Month, with Partition in Month
						}
					}//DesOrd
					break;//Option 3: Sort with Date of Purchase
				case 4:
					if(order==1){
						for(p=h->next;p;p=p->next){
							for(min=p,t=p->next;t;t=t->next)
								if(t->price<min->price) min=t;
							if(min!=p) Swap(min,p);
						}//Simple Selection Sort
					}//AscOrd
					else{
						for(p=h->next;p;p=p->next){
							for(max=p,t=p->next;t;t=t->next)
								if(t->price>max->price) max=t;
							if(max!=p) Swap(max,p);
						}//Simple Selection Sort
					}//DesOrd
					break;//Option 4: Sort with Price
				case 5:
					for(p=h;p->next;p=p->next);//Start Sorting from the End of Link List
					if(order==1&&h->next){//In Case that h->next==NULL
						while(p!=h->next){
							max=h->next;//max Is the Last Swaped Item in Unordered Part, Thus Area After It Is Sorted 
							for(t=h->next;t!=p;t=t->next){
								if(t->type>t->next->type){
									Swap(t,t->next);
									max=t;
								}
							}
							p=max;
						}//Bubble Sort
					}//AscOrd
					else if(order==2&&h->next){//In Case that h->next==NULL
						while(p!=h->next){
							min=h->next;//min Is the Last Swaped Item in Unordered Arear, Thus Area After It Is Sorted
							for(t=h->next;t!=p;t=t->next){
								if(t->type<t->next->type){
									Swap(t,t->next);
									min=t;
								}
							}
							p=min;
						}//Bubble Sort
					}//DesOrd
					break;//Option 5: Sort with Type
				case 6:
					p=h->next;//Start Sorting from h->next
					if(order==1){
						while(p){
							min=p,t=p->next;//t Traverses All Items to Be Sorted while min Is the Minimum among them
							while(t){
								if(t->index<min->index) min=t;
								t=t->next;	
							}
							if(min!=p) Swap(min,p);
							p=p->next;
						}//Simple Selection Sort
					}//AscOrd
					else{
						while(p){
							max=p,t=p->next;//t Traverses All Items to Be Sorted while max Is the Maximum among them
							while(t){
								if(t->index>max->index) max=t;
								t=t->next;	
							}
							if(max!=p) Swap(max,p);
							p=p->next;
						}//Simple Selection Sort
					}//DesOrd
					break;//Option 6: Sort with Index Number
			}//Sorting Completed
			printf("\nYou Have Successfully Sort the Library with ");
			switch(op){
				case 1:printf("Title");break;
				case 2:printf("Author");break;
				case 3:printf("Date of Purchase");break;
				case 4:printf("Price");break;
				case 5:printf("Type");break;
				case 6:printf("Index Number");break;
			}
			order==1?printf(" in Ascending Order:\n"):printf(" in Descending Order:\n");
			Traverse(h);//Show Sorting Result
		}//Sort with Fields
		printf("\nInput \"1\" to Continue Sorting, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Sorting
}//Function 4: Sort

void Delete(BookItem *&h){
	BookItem *p,*q;int key,i;
	printf("#Delete Book Items#\n");
	do{
		q=h,p=h->next;
		printf("Please Input the Index Number of the Book to be Deleted:\n");
		scanf("%d",&key);//Input Index Number
		while(p){
			if(p->index!=key) q=p,p=p->next;
			else break;
		}//Search for Matching Item. p Is to be Deleted while q is Its Precursor
		if(!p) printf("There is No Matching Item!\n");//Matching Failed
		else{
			printf("\nYou Have Successfully Delete the Item Listed Below:\n");
			Show(p);
			q->next=p->next;free(p);
		}//Item Deleted
		printf("\nInput \"1\" to Continue Deleting, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Deleting
}//Function 5: Delete Item with Index Number

void Revise(BookItem *&h){
	BookItem *p;int key,op,i,j;
	printf("#Revise Book Items#\n");
	do{
		p=h->next;//Prepare for Matching
		printf("Please Input the Index Number of the Item that Needs to be Revised.\n");
		scanf("%d",&key);
		while(p){
			if(p->index!=key) p=p->next;
			else break;
		}//Search for Matching Item p
		if(!p) printf("There is No Matching Item!\n");//Matching Failed
		else{
			printf("\nThe Item to be Revised is:\n");
			Show(p);
			do{
				printf("\nPlease Input the Field to Be Revised, Then Input the Revised Value:\n");
				printf("1:Title   2:Author   3:Date of Purchase   4:Price   5:Type\n");
				scanf("%d",&op);
				switch(op){
					case 1:
						char t[100];
						scanf("%s",t);
						strcpy(p->title,t);
						break;//Option 1: Revise Title
					case 2:
						char a[100];
						scanf("%s",a);
						strcpy(p->author,a);
						break;//Option 2: Revise Author
					case 3:
						scanf("%d%d%d",&p->date.year,&p->date.month,&p->date.day);
						break;//Option 3: Revise Date of Purchase
					case 4:
						scanf("%f",&p->price);
						break;//Option 4: Revise Price
					case 5:
						scanf("\n%c",&p->type);
						break;//Option 5: Revise Type 
					default:
						printf("Input Error!\n");
				}//Revise One Field
				printf("Input \"1\" to Continue Revising Other Fields of this Item, or \"0\" to Return to Function Revise\n");
				scanf("%d",&j);
			}while(j);//Revising Item
			printf("\nYou Have Successfully Revised this Item as:\n");
			Show(p);
		}//Item Matched Revised
		printf("\nInput \"1\" to Continue Revising, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Revising
}//Function 6: Revise Item with Index Number

void Import(BookItem *&h){
	int i;BookItem *t,*p,*q;
	printf("#Import Items from Files#\n");
	for(t=h;t->next;t=t->next);//t Is the Tail of the Existed Link List
	do{
		FILE *fin;char in[100]={};
		printf("\nPlease Input the Name of the File to be Imported in Current Directory.\nEg: Library.txt\n");
		scanf("%s",in);
		if((fin=fopen(in,"r"))==NULL) printf("\nCannot Open File \"%s\", or Such File Does Not Exist.\n",in);//Import Failed
		else{
			if(t->next){
				while(t->next) t=t->next;
			}//t Is the Tail of Current Link List
			for(p=t;!feof(fin);){
				q=(BookItem*)malloc(sizeof(BookItem));
				fscanf(fin,"%s%s%d%d%d%f %c%d\n",q->title,q->author,&q->date.year,&q->date.month,&q->date.day,&q->price,&q->type,&q->index);//Input Information of the Item to Be Added
				p->next=q,q->next=NULL,p=q;//Link the Node to Be Added to the End of Link List
			}
			fclose(fin);
			printf("\nYou Have Successfully Imported Item(s) Listed Below:\n");
			Traverse(t);
		}//Import Succeeded
		printf("\nInput \"1\" to Continue Importing, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Importing
}//Function 7: Import Items from (More than One) Files & Create Items, Intergrate with Exited List

void Export(BookItem *&h){
	BookItem *p;int i;
	printf("#Export Items to Files#\n");
	do{
		FILE *fout;char out[100]={};
		printf("Please Input the Name of the File to Export All Items to, Eg: Library.txt\n**If Such File Does not Exist in Current Directory, It Will be Created.\n");
		scanf("%s",out);
		if((fout=fopen(out,"w"))==NULL) printf("Exporting Failed. Cannot Open File \"%s\"",out);//Export Failed
		else{
			fprintf(fout,"Title	Author	Date of Purchase	Price	Type	Index Number\n");
			for(p=h->next;p;p=p->next){
				fprintf(fout,"%s	%s	%d/%02d/%02d		%.2f	%c	%d\n",p->title,p->author,p->date.year,p->date.month,p->date.day,p->price,p->type,p->index);
			}
			fclose(fout);
			printf("\nYou Have Successfully Exported All Items to File \"%s\".\n",out);
		}//Export Succeeded
		printf("\nInput \"1\" to Continue Exporting, or \"0\" to Return to Main Menu\n");
		scanf("%d",&i);
	}while(i);//Loop Exporting Items to Files
}//Fucntions 8: Export All Items to Files

int main(){
	BookItem *head;
	head=(BookItem*)malloc(sizeof(BookItem));
	head->next=NULL;//Initialize Head Node
	printf("\nWelcome to WHATEVER Library Management System!\nCopyright:Julius Song		04/25/2017");
	while(1){
		int op;
		printf("\n\n*******************************************************************\nInput a Number to Take Actions:\n");
		printf("1:Add Book Items	2:Traverse Book Items	3:Search Book Items\n4:Sort Book Items	5:Delete Book Items	6:Revise Library\n7:Import from Files	8:Export to Files	0:Exit System\n");
		printf("*******************************************************************\n\n");
		scanf("%d",&op);//8 Main Functions
		switch(op){
			case 1:Add(head);break;
			case 2:printf("#Traverse Library#\n");Traverse(head);break; 
			case 3:Search(head);break;
			case 4:Sort(head);break;
			case 5:Delete(head);break;
			case 6:Revise(head);break;
			case 7:Import(head);break;
			case 8:Export(head);break;
			case 0:printf("\nThank You for Using WHATEVER Library Management System!\n");exit(0);//Exit
			default:printf("Input Error!\n");
		}//Choose Action
	}//Loop Taking Actions
}//main
