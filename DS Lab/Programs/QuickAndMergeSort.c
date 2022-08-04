#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

struct student
{
	char name[20];
	float height;
	float weight;
};

int partition(struct student s[], int p, int r){
    struct student temp;
	float x = s[r].height;
	int i = p-1;
	for(int j = p; j < r; j++){
		if(s[j].height <= x){
			i=i+1;
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	}
	temp = s[i+1];
	s[i+1] = s[r];
	s[r] = temp;
	return i+1;
}

void quick_sort(struct student s[], int p, int r)
{
	if(p < r)
	{
		int q = partition(s, p ,r);
		quick_sort(s, p, q-1);
		quick_sort(s, q+1, r);
	}
}

void merge(struct student s[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int i,j;
	struct student L[n1], R[n2];

	for( i = 0; i <n1; i++){
		L[i] = s[p+i];
	}
	for(j = 0; j <n2;j++){
		R[j] = s[q+j+1];
	}
	i = 0, j = 0;
	int k;
	for(k = p; k <= r; k++){
		if(L[i].height <= R[j].height){
			s[k] = L[i];
			i=i+1;
			if(i == n1){
				k++;
				break;
			}
		}
		else{
			s[k] = R[j];
			j=j+1;
			if(j == n2){
				k++;
				break;
			}

		}
	}
	while(i < n1)
	{
		s[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		s[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(struct student s[], int p, int r)
{
	if(p < r)
	{
		int q = floor((p+r)/2);
		merge_sort(s, p, q);
		merge_sort(s, q+1, r);
		merge(s, p, q, r);
	}
}

void main()
{
	int n,i;
	char c,name[50];
	float height, weight;

	printf("Enter the Number of Students : ");
	scanf("%d", &n);

	FILE *fp1 = fopen("details.txt", "w");
	FILE *fp2 = fopen("details.txt", "r");
	FILE *fp3 = fopen("quick sort.txt", "w");
	FILE *fp4 = fopen("merge sort.txt", "w");
	struct student s1[50],s2[50];
	for( i=0; i<n; i++){
		printf("\nEnter the Details :\n");
		printf("  Name : ");
		scanf("%c", &c);
		gets(name);
		printf("  Height :");
		scanf("%f", &height);
		printf("  Weight : ");
		scanf("%f", &weight);
		fprintf(fp1,"%s\t%.3f\t%.3f\n",name,height,weight);
	}
	fclose(fp1);

	for( i = 0; i <n; i++){
		fscanf(fp2,"%s\t%f\t%f\n",s1[i].name, &s1[i].height, &s1[i].weight);
		strcpy(s2[i].name,s1[i].name);
		s2[i].height = s1[i].height;
		s2[i].weight = s1[i].weight;
	}
	fclose(fp2);


	clock_t start ,stop;
	start = clock();
	quick_sort(s1, 0, n-1);
	stop= clock() ;
	for(i = 0; i < n; i++){
		fprintf(fp3,"%s\t%.3f\t%.3f\n", s1[i].name, s1[i].height, s1[i].weight);
	}
	fprintf(fp3, "\nTime taken = %lf", (double) (stop-start) / CLOCKS_PER_SEC);
	fclose(fp3);

	start = clock();
	merge_sort(s2, 0, n-1);
	stop= clock();
	for(i = 0; i < n; i++){
		fprintf(fp4, "%s\t%.3f\t%.3f\n", s2[i].name, s2[i].height, s2[i].weight);
	}
	fprintf(fp4, "\nTime taken = %lf", (double) (stop-start)  / CLOCKS_PER_SEC);
	fclose(fp4);

}