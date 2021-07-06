#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct ArrayADT
{
    int capacity;
    int LastIndex;
    int *array;
};

struct ArrayADT* createArray(int capacity)
{
    struct ArrayADT *arr;
    arr=(struct ArrayADT*)malloc(sizeof(struct ArrayADT));
    arr->capacity=capacity;
    arr->LastIndex=-1;
    arr->array=(int*)malloc(arr->capacity*sizeof(int));
    return(arr);
}

void traverseArray (struct ArrayADT *arr)
{
    int i;
    if(arr->LastIndex==-1)
        printf("Array Empty");
    else
    {
        for(i=0;i<=arr->LastIndex;i++)
            printf("%d\t",arr->array[i]);
    }
}

void insertElement(struct ArrayADT *arr)
{
    int item,index,i;
    if(arr->LastIndex==arr->capacity-1)
        printf("Array overflow");
    else
    {
        printf("Enter new item &its index : \n");
        scanf("%d%d",&item,&index);
        if(index<0||index>arr->LastIndex+1)
            printf("Invalid Index");
        else
        {
            arr->LastIndex=arr->LastIndex+1;
            i=arr->LastIndex;
            while(i<index)
            {
                arr->array[i]=arr->array[i-1];
                i--;
            }
            arr->array[index]=item;
            printf("Item successfully Inserted");
        }
    }
}

void deleteItem(struct ArrayADT *arr)
{
    int item,index,i;
    if(arr->LastIndex==-1)
        printf("Array Underflow");
    else
    {
        printf("Enter Index : ");
        scanf("%d",&item);
        if(index<0||index>arr->LastIndex)
            printf("Invalid Index");
        else
        {
            item=arr->array[index];
            for(i=index;i<arr->LastIndex;i++)
            {
                arr->array[i]=arr->array[i+1];
            }
            arr->LastIndex--;
            printf("Remove Item :%d",item);
        }
    }
}


void main()
{
    struct ArrayADT *arr;
    int size,choice;
    printf("Enter size of array : ");
    scanf("%d",&size);
    arr=createArray(size);

    while(1)
    {
        system("cls");
        printf("Press\n1.Array Traverse\n2.Insert Item\n3.Delete Item\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            traverseArray(arr);break;
        case 2:
            insertElement(arr);break;
        case 3:
            deleteItem(arr);break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
getch();
    }
}
