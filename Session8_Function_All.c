#include<stdio.h>
#include<math.h>
#include<malloc.h>

int choice;
	
int list() {
	printf("\n 1. Linear Equation");
	printf("\n 2. Quadratic Equation");
	printf("\n 3. GCD and LCM");
	printf("\n 4. Pattern");
	printf("\n 5. Single Dimensional Array");
	printf("\n 6. Two Dimensional Array");
	printf("\n 7. Exit");
	do {
		printf("\n Please choose what you want to do [1-7]: ");
		scanf("%d",&choice);
	} while (choice<1&&choice>7);

	return choice;
}

//1. Linear Equation
void lineareq() {
	float a, b, x;
	printf("\n Solve linear equation: ax + b = 0");
	printf("\n Input coefficient a: ");
	scanf("%f",&a);
	printf("\n Input coefficient b: ");
	scanf("%f",&b);
	printf("\n You've input a = %.2f and b = %.2f.",a,b);
	printf("\n The equation is %.2fx + %.2f = 0.",a,b);
	if(a==0) {
		if(b==0) {
			printf("\n This equation has infinite solution.");
		}
		else {
			printf("\n This equation has no solution.");
		}
	}
	else if(b==0) {
		printf("\n This equation has solution x = 0.");
	}
	else {
		x = -b/a;
		printf("\n This equation has solution x = %.2f.",x);
	}	
}

//2. Quadratic Equation
void quadeq() {
	float a, b, c, delta, x, x1, x2;
	printf("\n Solve quadratic equation: ax^2 + bx + c = 0.");
	printf("\n Input coefficient a: ");
	scanf("%f",&a);
	printf("\n Input coefficient b: ");
	scanf("%f",&b);
	printf("\n Input coefficient c: ");
	scanf("%f",&c);
	printf("\n You've input a = %.2f, b = %.2f and c = %.2f.",a,b,c);
	printf("\n The equation is %.2fx^2 + %.2fx + %.2f = 0.",a,b,c);
	if(a==0) {
		if(b==0) {
			if(c==0) {
				printf("\n This equation has infinite solution.");
			}
			else {
				printf("\n This equation has no solution as a and b coefficient are equal to 0 but c isn't.");
			}
		}
		else if (c==0) {
			printf("\n This equation has solution x = 0.");
		}
		else {
			x = -c/b;
			printf("\n This equation has solution x = %.2f.",x);
		}
	}
	else {
		delta=pow(b,2)-4*a*c;
		if(delta<0) {
			printf("\n This equation has no solution as delta < 0.");
		}
		else if(delta==0) {
			x = -b/(2*a);
			printf("\n This equation has a double root solution x = %.2f.",x);
		}
		else {
			x1 = (-b+sqrt(delta))/(2*a);
			x2 = (-b-sqrt(delta))/(2*a);
			printf("\n This equation has two solutions x1 = %.2f va x2 = %.2f",x1,x2);
		}
	}
}

//3. GCD, LCM
void gcdlcm() {
	int a, b, A, B, gcd, lcm;
	
	printf("\n Input integer A and B to find their greatest common divisor (GCD) and least common multiple (LCM):");
	printf("\n Input A: ");
	scanf("%d",&A);
	printf("\n Input B: ");
	scanf("%d",&B);
	
	a = abs(A);
	b = abs(B);
	
	if(A==B&&A==0) {
		printf("\n GCD and LCM of A and B are both 0.");		
	}
	else if(A==0||B==0) {
		if(a>b) {
			printf("\n GCD of A and B is: %d", a);
		}
		else {
			printf("\n GCD of A and B is: %d", b);
		}
		printf("\n LCM of A and B is: 0");			
	}
	else if(a==b) {
		printf("\n GCD and LCM of A and B are: %d", a);
	}	
	else {
		while(a!=0&&b!=0) {
			if(a>b) {
				a = a%b;
			}
			else {
				b = b%a;
			}
		}
		if (a!=0) {
			printf("\n GCD of A and B is: %d", a);
			lcm = abs(A)*abs(B)/a;
			printf("\n LCM of A and B is: %d", lcm);			
		}
		else {
			printf("\n GCD of A and B is: %d", b);
			lcm = abs(A)*abs(B)/b;	
			printf("\n LCM of A and B is: %d", lcm);
		}
	}
}

//4. Pattern
void pattern() {
	int i,j,k;
	int A;
	
	do {
		printf("\n Input integer A which is greater than 1: ");
		scanf("%d",&A);
	} while (A<=1);
	
	printf("\n Right Triangle:");
	printf("\n");
	for(i=1;i<=A;i++) {	
		printf(" ");
		for(j=1;j<=i;j++) {
			printf("* ");
		}
		printf("\n");
	}
	
	printf("\n Reversed Right Triangle:");
	printf("\n");
	for(i=1;i<=A;i++) {	
		printf(" ");
		for(j=0;j<i-1;j++) {
			printf("  ");
		}
		for(k=0;k<=A-i;k++) {
			printf("* ");
		}
		printf("\n");
	}
	
	printf("\n Filled Square:");
		printf("\n");
		for(i=1;i<=A;i++) {	
		printf(" ");
		for(j=1;j<=A;j++) {
			printf("* ");
		}
		printf("\n");
	}
	
	printf("\n Hollowed Square:");
	printf("\n");
	for(i=1;i<=A;i++) {
		printf(" ");
		for(j=1;j<=A;j++) {
			if(i==1||i==A||j==1||j==A) {
				printf("* ");
			}
			else printf("  ");
		}
		printf("\n");
	}
}

//5. Array >> min, max, reverse, sorting, find value
void array1() {
	int i,n;
	int *arr,*revarr;
	int max,min;
	
	//Input array
	printf("\n Input how many integer you want to input: ");
	scanf("%d",&n);
	arr = calloc(n,sizeof(int));
	revarr = calloc(n,sizeof(int));
	
	for(i=0;i<n;i++) {	
		printf("\n Input number at position %d of the sequence: ",i+1);
		scanf("%d",arr+i);
	}
	
	//Print array	
	printf("\n The sequence that have been inputed: ");
	for(i=0;i<n;i++) {
		printf("%d ",*(arr+i));
	}
	
	int choice;
	int searchvalue;
	printf("\n 1. Find max value. ");
	printf("\n 2. Find min value. ");
	printf("\n 3. Find a value. ");
	printf("\n 4. Print the reversed sequence. ");
	do {
		printf("\n What do you want to do?[1-4]: ");
		scanf("%d",choice);	
	} while (choice<1&&choice>4);
	
	switch (choice) {
		case 1: //Max value	
			max=*arr;
			for(i=0;i<n;i++) {	
				if(max<*(arr+i)) {
					max=*(arr+i);
				}
			}
			printf("\n The max value of the inputed sequence is: %d",max);
			break;
		case 2: //Min value
			min=*arr;
			for(i=0;i<n;i++) {	
				if(min>*(arr+i)) {
					min=*(arr+i);
				}
			}
			printf("\n The min value of the inputed sequence is: %d",min);
			break;
		case 3: //Find value
			printf("\n Input an integer that you want to find in the sequence: ");
			scanf("%d",&searchvalue);
			
			int flag=0;
			for(i=0;i<n;i++)
			{
				if(searchvalue==arr[i])
				{
					flag++;
				}
			}
			printf("So %d da xuat hien %d lan trong mang so.",searchvalue, flag);
			break;
		case 4: //Reverse sequence
			for(i=0;i<n;i++) {
				*(revarr+n-1-i)=*(arr+i);
			}
			printf("\n The reversed sequence of the inputed one is: ");
			for(i=0;i<n;i++) {
				printf("%d ",*(revarr+i));
			}
			break;
	}
}

//6. 2D Array >> min max each row/column, main diagonal sum, find value
void array2() {
	int i,j,n,m;
	int sum=0;
	int minr,maxr,minc,maxc;
	
	do {
		printf("\n Input m and n to create a table of integer with m row and n column: ");
		scanf("%d",&m);
		scanf("%d",&n);
	} while(m<1||n<1);
	
	int arr[m][n];
	
//Input array
	printf("\n Please input the integers: ");
	for(i=0;i<m;i++) {	
		for(j=0;j<n;j++) {
			printf("\n Integer of row %d, column %d is: ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}		
	}
	
//Print array	
	printf("\n The table you have inputted is: ");
	for(i=0;i<m;i++) {	
		for(j=0;j<n;j++) {
			printf(" %d",arr[i][j]);
		}	
	}

//Main diagonal sum
	if(m>n) {
		for(i=0;i<n;i++) {
			sum=sum+arr[i][i];	
		}				
		printf("\n The sum of main diagonal is: %d",sum);
	}
	else {
		for(i=0;i<m;i++) {
			sum=sum+arr[i][i];	
		}				
		printf("\n The sum of main diagonal is: %d",sum);	
	}
	
//Max value in each row
	printf("\n");
	for(i=0;i<m;i++)
	{	
		j=0;
		maxr=arr[i][j];
		for(j=0;j<n;j++)
		{
			if(maxr<arr[i][j])
			{
				maxr=arr[i][j];
			}	
		}
		printf("\n Max value in row %d is: %d",i+1,maxr);
	}
	
//Min value in each row
	printf("\n");
	for(i=0;i<m;i++) {	
		j=0;
		minr=arr[i][j];
		for(j=0;j<n;j++) {
			if(minr>arr[i][j]) {
				minr=arr[i][j];
			}	
		}
		printf("\n Min value in row %d is: %d",i+1,minr);
	}
	
//GTLN trong cot
	printf("\n");	
	for(j=0;j<n;j++)
	{	
		i=0;
		maxc=arr[i][j];
		for(i=0;i<m;i++)
		{
			if(maxc<arr[i][j])
			{
				maxc=arr[i][j];
			}	
		}
		printf("\n Gia tri lon nhat trong cot %d: %d",j+1,maxc);
	}

//GTNN trong cot	
	printf("\n");
	
	for(j=0;j<n;j++)
	{	
		i=0;
		minc=arr[i][j];
		for(i=0;i<n;i++)
		{
			if(minc>arr[i][j])
			{
				minc=arr[i][j];
			}	
		}
		printf("\n Gia tri nho nhat trong cot %d: %d",j+1,minc);
	}
}

int main() {
	list();
	switch (choice) {
		case 1:
			lineareq();
			break;
		case 2:
			quadeq();
			break;
		case 3:
			gcdlcm();
			break;
		case 4:
			pattern();
			break;
		case 5:
			array1();
			break;
//		case 6:
//			array2();
//			break;
	}
		
}



