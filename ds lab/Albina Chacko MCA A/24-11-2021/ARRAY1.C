#include<stdio.h>
#include<stdlib.h>
int main()
{
int a[100],pos,i,n,val,choice=1,ch,flag=0;
printf("enter number of elements in array\n");
scanf("%d",&n);
printf("enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
while(choice>0&&choice<6)
{
printf("\n1.insertion\n2.traversal\n3.deletion\n4.searching\n5.exit\n");
printf("enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter the location to insert an element");
scanf("%d",&pos);
printf("enter the value to insert\n");
scanf("%d",&val);
for(i=n-1;i>=pos-1;i--)
{
a[i+1]=a[i];
}
a[pos-1]=val;
printf("After insertion\n");
for(i=0;i<n+1;i++)
{
printf("%d\t",a[i]);
}
break;
case 2:
printf("After array traversal: ");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
break;
case 3:
printf("enter the location to delete an array: ");
scanf("%d",&pos);
for(i=pos-1;i<n;i++)
{
a[i]=a[i+1];
}
printf("resultant array:\n");
for(i=0;i<n-1;i++)
{
printf("%d\n",a[i]);
}
break;
case 4:
printf("enter the element to search: ");
scanf("%d",&ch);
for(i=0;i<n;i++)
{
if(a[i]==ch)
{
flag=1;
break;
}
}
if(flag==1)
{
printf("%d found at %d at position\n",ch,i+1);
}
else
{
printf("%d is not found",ch);
}
break;
case 5:
exit(0);
break;
default:
printf("This option is not found");
}
}
return 0;
}
