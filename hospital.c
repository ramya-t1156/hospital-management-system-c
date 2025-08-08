#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct hospital{
	char name[30];
	char disease[30];
	int age,phone,room;
}x[100];

struct doctor{
	char name[30];
	char specialization[30];
	int experience;
	char timings[50];//Adding timing information for doctors
	float fees;//Adding consultation fees for doctors
};

struct appointment{
	char patient_name[30];
	char doctor_name[30];
	char date[20];
	char time[20];//appointment time
};

struct billing{
	char patient_name[30];
	float total_bill;
};
struct hospital patients[100];
struct doctor doctors[20];
struct appointment appointments[50];
struct billing bills[50];
int n,i,j,num=2,sum=0,num_doctors=5,num_appointment=0,num_bills=0;

void read();
void add();
void view();
void search();
void edit();
void del();
void add_doctor();
void view_doctor();
void take_appointment();
void view_appointment();
void generate_bill();
void addDefaultPatients();
void default_doctor();
void savePatientsToFile(); 
void saveDoctorsToFile();
void loadPatientsFromFile();
void loadDoctorsFromFile();

void search(){
	int op,s;
	char a[30];
	printf("By What do you want to search ?\n");
	printf("1.Serial no\n2.Name\n3.Disease\n4.Room no\n5.Phone no\n6.Age\n");
	printf("Enter option : ");
	scanf("%d",&op);
	if (op == 1) {
        int s;
        printf("Enter Serial number of the Patient: ");
        scanf("%d", &s);
        if (s>=0&&s<num) {
            printf("\n");
            printf("Serial Number : %d\n",s);
            printf("Name          : %s\n",x[s].name);
            printf("Disease       : %s\n",x[s].disease);
            printf("Room no       : %d\n",x[s].room);
            printf("Age           : %d\n",x[s].age);
            printf("Phone no      : %d\n",x[s].phone);
        } else {
            printf("\n\nNot found\n\n");
        }
	}
	else if(op==2){
		int r=1,a=0;
		char na[30];
		printf("Enter the Name of the Patient : ");
		scanf("%s",na);
		for(;a<num;a++){
			if(strcmp(na,x[a].name)==0){
				printf("\n");
				printf("Serial Number : %d",a);
				printf("\nName          : %s",x[a].name);
				printf("\nDisease       : %s",x[a].disease);
				printf("\nRoom no       : %d",x[a].room);
				printf("\nAge           : %d",x[a].age);
				printf("\nPhone no      : %d",x[a].phone);
				r=0;
			}
		}
		if(r==1){
			printf("\nNot Found\n");
		}
	}
	else if(op==3){
		int r=1,a=0;
		char na[30];
		printf("Enter Disease  : ");
		scanf("%s",na);
		for(;a<num;a++){
			if(strcmp(na,x[a].disease)==0){
				printf("\n");
				printf("Serial Number : %d",a);
				printf("\nName          : %s",x[a].name);
				printf("\nDisease       : %s",x[a].disease);
				printf("\nRoom no       : %d",x[a].room);
				printf("\nAge           : %d",x[a].age);
				printf("\nPhone no      : %d",x[a].phone);
				r=0;
			}
		}
		if(r==1){
			printf("\nNot Found\n");
		}
	}	
	else if(op==4){
		int r=1,a=0,na;
		printf("Enter Room no  : ");
		scanf("%d",&na);
		for(;a<num;a++){
			if(na==x[a].room){
				printf("\n");
				printf("Serial Number : %d",a);
				printf("\nName          : %s",x[a].name);
				printf("\nDisease       : %s",x[a].disease);
				printf("\nRoom no       : %d",x[a].room);
				printf("\nAge           : %d",x[a].age);
				printf("\nPhone no      : %d",x[a].phone);
				r=0;
			}
		}
		if(r==1){
			printf("\nNot Found\n");
		}
	}	
	else if(op==5){
		int r=1,a=0,na;
		printf("Enter Phone number  : ");
		scanf("%d",&na);
		for(;a<num;a++){
			if(na==x[a].phone){
				printf("\n");
				printf("Serial Number : %d",a);
				printf("\nName          : %s",x[a].name);
				printf("\nDisease       : %s",x[a].disease);
				printf("\nRoom no       : %d",x[a].room);
				printf("\nAge           : %d",x[a].age);
				printf("\nPhone no      : %d",x[a].phone);
				r=0;
			}
		}
		if(r==1){
			printf("\nNot Found\n");
	    }
	}	
	else if(op==6){
		int r=1,na,a=0;
		printf("Enter Age  : ");
		scanf("%d",&na);
		for(;a<num;a++){
			if(na==x[a].age){
				printf("\n");
				printf("Serial Number : %d",a);
				printf("\nName          : %s",x[a].name);
				printf("\nDisease       : %s",x[a].disease);
				printf("\nRoom no       : %d",x[a].room);
				printf("\nAge           : %d",x[a].age);
				printf("\nPhone no      : %d",x[a].phone);
				r=0;
			}
		}
		if(r==1){
			printf("\nNot Found\n");
	    }
	}
	else{
		printf("\n\nInvalid Input\n\n");
	}	
}
void addDefaultPatients(){
    strcpy(x[0].name, "John Doe");
    strcpy(x[0].disease, "Fever");
    x[0].age = 35;
    x[0].room = 101;
    x[0].phone=123450;
    strcpy(x[1].name, "Jane Smith");
    strcpy(x[1].disease, "Fracture");
    x[1].age = 40;
    x[1].room=105;
    x[1].phone=9876;
}
void default_doctor(){
	strcpy(doctors[0].name, "Dr. Smith");
	strcpy(doctors[0].specialization, "Pediatrics");
	doctors[0].experience = 10;
	strcpy(doctors[0].timings, "9 AM - 5 PM");
	doctors[0].fees = 100.0;
	
	strcpy(doctors[1].name, "Dr. Johnson");
	strcpy(doctors[1].specialization, "Cardiology");
	doctors[1].experience = 15;
	strcpy(doctors[1].timings, "10 AM - 6 PM");
	doctors[1].fees = 120.0;
	
	strcpy(doctors[2].name, "Dr. Williams");
	strcpy(doctors[2].specialization, "Orthopedics");
	doctors[2].experience = 12;
	strcpy(doctors[2].timings, "8 AM - 4 PM");
	doctors[2].fees = 110.0;

	strcpy(doctors[3].name, "Dr. Brown");
	strcpy(doctors[3].specialization, "Dermatology");
	doctors[3].experience = 8;
	strcpy(doctors[3].timings, "11 AM - 7 PM");
	doctors[3].fees = 130.0;

	strcpy(doctors[4].name, "Dr. Miller");
	strcpy(doctors[4].specialization, "Neurology");
	doctors[4].experience = 20;
	strcpy(doctors[4].timings, "7 AM - 3 PM");
	doctors[4].fees = 150.0;
    
}
void add_doctor(){
	int a,sum1;
	printf("Already data inputed in database : %d\n",num_doctors);
	printf("How many entry do you want to add : ");
	scanf("%d",&a);//n is how many inputs
	sum1=num_doctors+a;//old data+input data=total data
	for(i=num_doctors;i<sum1;i++){
		printf("\n");
		printf("\nEnter....");
		printf("\nDoctor's Name                 : ");
		scanf("%s",doctors[num_doctors].name);
		printf("Doctor's Specialization       : ");
		scanf("%s",doctors[num_doctors].specialization);
		printf("Doctor's Experience(in years) : ");
		scanf("%d",&doctors[num_doctors].experience);
		printf("Doctor's Timings              : ");
		scanf("%s",doctors[num_doctors].timings);
		printf("Doctors's Consultation Fees  : ");
		scanf("%f",&doctors[num_doctors].fees);
		num_doctors++;
	}
	printf("\nDoctor information added successfully!!");
}
void view_doctor(){
	int i=0;
	default_doctor();
	for(;i<num_doctors;i++){
		printf("\nSerial Number	: %d",i+1);
		printf("\nDoctor's Name           : %s",doctors[i].name);
		printf("\nDoctor's Specialization : %s",doctors[i].specialization);
		printf("\nDoctor's Experience     : %d years",doctors[i].experience);
		printf("\nDoctor's Timings        : %s",doctors[i].timings);
		printf("\nDoctors's Consultation Fees   : %.2f",doctors[i].fees);
		printf("\n\n");
	}
}
void take_appointment(){
	printf("\nEnter...");
	printf("\nPatient's Name    : ");
	scanf("%s",appointments[num_appointment].patient_name);
	printf("Doctor's Name     : ");
	scanf("%s",appointments[num_appointment].doctor_name);
	printf("Appointment Date  : ");
	scanf("%s",appointments[num_appointment].date);
	printf("Appointment Time  : ");
	scanf("%s",appointments[num_appointment].time);
	num_appointment++;
}
void view_appointment(){
	int i=0;
	printf("\nList of Appointments : \n");
	for(;i<num_appointment;i++){
		printf("\nPatient's Name     : %s",appointments[i].patient_name);
		printf("\nDoctor's Name      : %s",appointments[i].doctor_name);
		printf("\nAppointment Date   : %s",appointments[i].date);
		printf("\nAppointment Time   : %s",appointments[i].time);
	}
}
void generate_bill(){
	printf("\nEnter Patient's Name : ");
	scanf("%s",bills[num_bills].patient_name);
	bills[num_bills].total_bill=50.0;
	num_bills++;
}

void clearScreen(){
    system("cls");
}

int main(){
	loadPatientsFromFile();
    loadDoctorsFromFile();
	read();
	int choice=0;
	printf("\t_________________________________________________________________\n\n ");
	printf("\t\tSIMPLE HOSPITAL MANAGEMENT SYSTEM\n");
	printf("\t_________________________________________________________________\n\n");
	while(choice!=11)
	{
	printf("**Enter your choice**\n\n");
	printf("1.Add Patient's Information\n2.View Information\n3.Search Information\n4.Edit Information\n5.Delete Information\n6.Add Doctor information\n7.View Doctor Information\n8.Take Appointment\n9.View Appointment\n10.Generate Bill\n11.Exit\n\nEnter your choice :");
	scanf("%d",&choice);
	clearScreen();
	if(choice==1){
		add();
		system("cls");
		printf("\nData Added Successfully!!!\n");
	}
	else if(choice==2){
		view();
	}
	else if(choice==3){
		search();
	}
	else if(choice==4){
		edit();
		system("cls");
		printf("\nData Edited Successfully!!!\n");
	}
	else if(choice==5){
		del();
		system("cls");
		printf("\nData Delited Successfully!!!\n");
	}
	else if(choice==6){
		add_doctor();
		system("cls");
		printf("\nData Added Successfully!!!\n");
	}
	else if(choice==7){
		view_doctor();
	}
	else if(choice==8){
		take_appointment();
		system("cls");
		printf("\nAppointment taken Successfully!!!\n");
	}
	else if(choice==9){
		view_appointment();
	}
	else if(choice==10){
		generate_bill();
		printf("\nBill Generated Successfully!!!\n\n");
	}
	else if(choice==11){
        return 0;  
    }  
	else{
		printf("\n\nInvalid input!!!!!\nIf you want enter Valid input\n\n");
	}
	printf("\n\n");
	}
	atexit(savePatientsToFile);
    atexit(saveDoctorsToFile);
	return 0;
}
void add(){
	//num is the count of datas
	printf("Already data inputed in database : %d\n",num);
	printf("How many entry do you want to add : ");
	scanf("%d",&n);//n is how many inputs
	sum=num+n;//old data+input data=total data
	for(i=num;i<sum;i++){
		printf("\n");
		
		printf("Enter...\n1. Patient's Name : ");
		scanf("%s",x[i].name);
		printf("2. Disease        : ");
		scanf("%s",x[i].disease);
		printf("3. Age            : ");
		scanf("%d",&x[i].age);
		printf("4. Room number    : ");
		scanf("%d",&x[i].room);
		printf("5. Phone number   : ");
		scanf("%d",&x[i].phone);
		num++;
	}
}

void view(){
	addDefaultPatients();
	for(i=0;i<num;i++){
		printf("\nSerial Number : %d\n",i+1);
		printf("\nName          : %s",x[i].name);
		printf("\nDisease       : %s",x[i].disease);
		printf("\nAge           : %d",x[i].age);
		printf("\nRoom no       : %d",x[i].room);
		printf("\nPhone number  : %d",x[i].phone);
		printf("\n\n");
	}
}
void edit(){
	int option,aa;
	printf("What do you want to edit ?\n");
	printf("1.Name\n2.Disease\n3.Age\n4.Room\n5.Phone no");
	printf("\nEnter your option \n");
	scanf("%d",&option);
	if(option<=5){
		printf("Enter the serial no of the patient(0-%d) : ",num-1);
		scanf("%d",&aa);
		if(aa<num){
			if(option==1){
				printf("Enter the new name : ");
				scanf("%s",x[aa].name);
		    }
		    else if(option==2){
		    	printf("Enter the new Disease :" );
				scanf("%s",x[aa].disease);	
			}
			else if(option==3){
		    	printf("Enter the new Age :" );
				scanf("%d",&x[aa].age);	
			}
			else if(option==4){
		    	printf("Enter the new Room no :" );
				scanf("%d",&x[aa].room);	
			}
			else if(option==5){
		    	printf("Enter the new Phone number :" );
				scanf("%d",&x[aa].phone);	
			}
			else{
				printf("\n\nInvalid Serial\nTry Again!!\n\n");
			}
		}
		else{
			printf("\n\nInvalid option\nTry Again!!\n\n");
	}	}	
}
void del(){
	int s,rem;
	printf("Enter the serial number of the patient that do you want to delete : ");
	scanf("%d",&s);
	if(s<num){
		printf("What to do you want ?\n");
		printf("1.Remove the record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n4.Remove room no\n5.Remove Phone number\n");
		printf("Enter option : ");
		scanf("%d",&rem);
		if(rem==1){
			while(s<num){
				strcpy(x[s].name,x[s+1].name);
				strcpy(x[s].disease,x[s+1].disease);
				x[s].age=x[s+1].age;
				x[s].room=x[s+1].room;
				x[s].phone=x[s+1].phone;
				s++;
			}
			num--;
		}
		else if(rem==2){
			strcpy(x[s].name,"not entered");
		}
		else if(rem==3){
			strcpy(x[s].disease,"not entered");
		}
		else if(rem==4){
			x[s].age=0;
		}
		else if(rem==5){
			x[s].room=0;
		}
		else if(rem==6){
			x[s].phone=0;
		}
	}
	else{
		printf("\n\nInvalid Serial number\n");	
	}
	printf("\nRemoved Successfuly!!");
}
void savePatientsToFile(){
    FILE *file = fopen("patients.txt", "wb");
    if (file != NULL) {
        fwrite(patients, sizeof(struct hospital), num, file);
        fclose(file);
    } else {
        printf("Error opening file!\n");
    }
}
void saveDoctorsToFile(){
    FILE *file = fopen("doctors.txt", "wb");
    if (file != NULL) {
        fwrite(doctors, sizeof(struct doctor), num_doctors, file);
        fclose(file);
    } else {
        printf("Error opening file!\n");
    }
}
void loadPatientsFromFile(){
    FILE *file = fopen("patients.txt", "rb");
    if (file != NULL) {
        fread(patients, sizeof(struct hospital), 100, file); // Assuming the max capacity is 100
        fclose(file);
    } else {
        printf("Error opening file!\n");
    }
}
void loadDoctorsFromFile(){
    FILE *file = fopen("doctors.txt", "rb");
    if (file != NULL) {
        fread(doctors, sizeof(struct doctor), 20, file); // Assuming the max capacity is 20
        fclose(file);
    } else {
        printf("Error opening file!\n");
    }
}
