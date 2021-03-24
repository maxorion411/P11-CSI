P11-1:
	
#include<stdio.h>
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10] = {2,3,4,3,4,6,7,8,1,9,12};
	int i,count = 0;
	for(i = 0; i < 10; i++){
		if(a[i] == b[i]){
			count++;
		}
	}
	if(count == 10){
		printf("a = b\n");
	} else {
		printf("a != b\n");
	}
}

P11-2:
#include<stdio.h>
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,j,temp = 0;
	for(i = 9 ; i  > 4; i++){
		a[10 - i - 1] = temp;
		a[10-i-1] = a[i];
		a[i] = temp;
	}
	for(i = 0; i<10;i++){
		printf("%d ", a[i]);
	}

}

P11-3:
#include<stdio.h>
int main(){
	int a[2][10] = {{1,2,3,4,5,6,7,8,9,10},{23,3,45,3,234,5,5,23,4,56}};
	int i,j;
	for(i = 0; i < 2;i++){
		for(j = 0; j < 10;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

P11-4:
#include<stdio.h>
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,j;
	int x = 6;
	for(i = 0; i < 10;i++){
		if(a[i] == x){
			printf("Array have element x in position %d", i);
			return 0;
		}
	}
}

P11-5:
#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
 	return -1;
}
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("Find x at position %d",binarySearch(a,0,10,6));
}

P11-6:
#include<stdio.h>
#include<conio.h>
int xuatmang(int a[],int n)
 {
  int i;
  for(i=0;i<n;i++)
    {
      printf(" %d ",a[i]);
    }
    printf("\n");
 }

void chen(int a[],int *n,int k, int x)
{
 int i;
 *n+=1;
 for(i=*n;i>k;i--)
 {
 a[i]=a[i-1];
 }
 a[k]=x;
 printf("Sau khi chen x = %d vao vi tri %d:\n",x,k);
 xuatmang(a,*n);
 
}

int main()
{
 int a[10] = {1,2,2,4,5,6,7,8,9,10};
 int n = 10,temp,i,k;
 int x = 6;
 for(i = 0; i <10; i++){
 	if(a[i] > a[i+1]){
 	 	a[i] = temp;
 		a[i] = a[i+1];
		a[i+1] = temp;	
	 }
 }
 for(i = 0; i <10;i++){
 	if(x >= a[i] && x <= a[i+1]){
 		k = i+1;
 		break;
	 }
 }

 xuatmang(a,n);
 printf("Vi tri chen: %d\n", k);
 chen(a,&n,k,x);
 return 0;
}

P11-7:
#include<stdio.h>
#include<conio.h>
int xuatmang(int a[],int n)
 {
  int i;
  for(i=0;i<n;i++)
    {
      printf(" %d ",a[i]);
    }
    printf("\n");
 }

void xoa(int a[],int *n,int k)
{
 int i;
 for(i=k;i < *n;i++){
 	a[i] = a[i+1];
 }
 *n-=1;

}

int main()
{
 int a[10] = {1,2,2,4,5,6,7,8,9,10};
 int n = 10,temp,i,k;
 int x = 6;
 for(i = 0; i <10; i++){
 	if(a[i] > a[i+1]){
 	 	a[i] = temp;
 		a[i] = a[i+1];
		a[i+1] = temp;	
	 }
 }
 for(i = 0; i <10;i++){
 	if(x == a [i]){
 		k = i;
 		break;
	 }
 }

 xuatmang(a,n);
 printf("Vi tri xoa: %d\n", k);
 xoa(a,&n,k);
 printf("Sau khi xoa x = %d:\n",x);
 xuatmang(a,n);
 return 0;
}

P11-8: 
#include<stdio.h>
int main(){
    int a[5] ={33,4,22,3,55};
    int i;
	const int b = 2;
	for(i = 0 ;i<5;i++){
		a[i] = b * a[i];
		printf("%d ",a[i]);
	}
	return 0;
}


P11-9,10,11,12:
	
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int USCLN(int a, int b)
{
  a = abs(a);
  b = abs(b);
  while (a != 0 && b != 0)
    if (a > b)
      a -= b;
    else
      b -= a;
  if (a == 0)
    return b;
  else
    return a;
}

int BSCNN(int a, int b)
{
   return a * b / USCLN(a, b);
}

typedef struct tagphanso 
{
  int tuso, mauso;
} PHANSO;

PHANSO uocluoc(PHANSO a)
{
  PHANSO c;
  c.tuso = a.tuso / USCLN(a.tuso, a.mauso);
  c.mauso = a.mauso / USCLN(a.tuso, a.mauso);
  return c;
}

PHANSO cong(PHANSO a, PHANSO b)
{
  PHANSO c;
  c.tuso = a.tuso * b.mauso + a.mauso * b.tuso;
  c.mauso = a.mauso * b.mauso;
  c = uocluoc(c);
  return c;
}

PHANSO tru(PHANSO a, PHANSO b)
{
  PHANSO c;
  c.tuso = a.tuso * b.mauso - a.mauso * b.tuso;
  c.mauso = a.mauso * b.mauso;
  c = uocluoc(c);
  return c;
}

PHANSO nhan(PHANSO a, PHANSO b)
{
  PHANSO c;
  c.tuso = a.tuso * b.tuso;
  c.mauso = a.mauso * b.mauso;
  c = uocluoc(c);
  return c;
}

PHANSO chia(PHANSO a, PHANSO b)
{
  PHANSO c;
  c.tuso = a.tuso * b.mauso;
  c.mauso = a.mauso * b.tuso;
  c = uocluoc(c);
  return c;
}
void print(PHANSO a)
{
  printf("%d/%d", a.tuso, a.mauso);
}
int main()
{
  PHANSO a, b, c;
  a.tuso = 4;
  a.mauso = 5;
  b.tuso = 6;
  b.mauso = 7;
  printf("\nphan so a : %d/%d",a.tuso,a.mauso);
  printf("\nphan so b : %d/%d",b.tuso,b.mauso);
  printf("\nToi gian a ta duoc : ");
  a = uocluoc(a);
  print(a);
  printf("\nToi gian b ta duoc : ");
  b = uocluoc(b);
  print(b);
  printf("\nTong cua hai phan so = ");
  c = cong(a, b);
  print(c);
  printf("\nHieu cua hai phan so = ");
  c = tru(a, b);
  print(c);
  printf("\nTich cua hai phan so = ");
  c = nhan(a, b);
  print(c);
  printf("\nThuong cua hai phan so = ");
  c = chia(a, b);
  print(c);
  getch();
}
