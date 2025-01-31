
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


// following are the some structures used in my project 
struct patient     //patient structure
{

    int id;
    char name[50];
    char gender;
    int age;
    char disease[50];
    int bed_no;
    char dc_name[50];
    int dc_id;
    char ward[20];
    int wd_id;

    char admission_date[20];
    int admision_status;
    char discharge_date[20];
};

struct doctor //docture structure
{
    int id;
    char name[50];
    char gender;
    char speacialization[25];
};
struct ward   //ward structure
{
    int id;
    char name[50];
    int capacity;
};
struct appointment  //appointment structure
{
    int id;
    char pt_name[50];
    int doctor_id;
    char dc_name[50];
    char reason[100];
    char date[20];
};
struct medicines        //medicine structue
{

    int id;
    char name[50];
    int price;
    int availibility_status;
};


// followind are prototypes of all fucitons used in my project


//following funtions are for menu control
void mainmenu();
void managedata_Menu();
void search_menu();
void report_menu();


//following funtions are for patient mangement
void addPatient();
void update_pt(int index);
void delete_pt(int index);
int searchpt_By_Name(char name[]);
int searchpt_By_Id(int id);
void print_pt(int index);


//following functions are for doctor management
int searchdc_By_Id(int id);
void addDoctor();
void update_dc(int index);
void delete_dc(int index);
void print_dc(int index);


//following funtions are for medicine managment
void addMedicine();
void update_md(int index);
int searchmd_By_Id(int id);
void delete_md(int index);
void print_md(int index);

//follwing funciotns are for ward managment
void addWard();
void update_wd(int index);
void delete_wd(int index);
int searchwd_By_Id(int id);
void print_wd(int index);

//following funtions are for appointment managment
void addAppointment();
void update_ap(int index);
void delete_ap(int index);
void print_ap(int index);
int searchap_By_Id(int id);

//following funtions are for report generation
void pt_ad_report(char ad_date[]);
void pt_dis_report(char dis_date[]);
void pt_by_dc(char doc[]);
void ap_by_dc(char doc[]);
void ap_by_date(char date[]);
void md_by_as(int availability);


//following are the funtions for fetching and saving data on disk 
void fetch_data();
void feed_data();

int choice;
int pt_count = 0, dc_count = 0, wd_count = 0, ap_count = 0, md_count = 0;
struct patient pt[100];
struct doctor dc[10];
struct ward wd[10];
struct appointment ap[500];
struct medicines md[100];

int main()
{
    system("COLOR 0B");
    fetch_data();
    mainmenu();
    return 0;
}

void mainmenu()
{

    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t__________________________________________________________________\n");
        printf("\t\t\t\t\t\t\t\t*****   ***   WELCOME TO HOSPITAL MANAGMENT SYSTEM   ***   *****");
        printf("\n\t\t\t\t\t\t\t\t__________________________________________________________________\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t****  MAIN MENU  ****\n\n");
        printf("\n\n\n\t\t\t\t\t\t\t\t1.  Manage Data \n\t\t\t\t\t\t\t\t2.  Search\n\t\t\t\t\t\t\t\t3.  Reports\n\t\t\t\t\t\t\t\t4.  Exit\n");
        printf("\n\t\t\t\t\t\t\t\tYour choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            managedata_Menu();
            break;

        case 2:
            search_menu();
            break;

        case 3:
            report_menu();
            break;

        case 4:
            feed_data();
            printf("Shutting Down");
            Sleep(2);
            system("cls");
            break;

        default:

            printf("I am form case default");
            break;
        }

    } while (choice != 4);
}

void managedata_Menu()
{
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** MANAGE DATA MENU **** ******\n\n");
        printf("\t\t\t\t\t\t\t\t\t_________________________________________________________\n\n");
        printf("\t\t\t\t\t\t\t\t1.  Add Data \n\t\t\t\t\t\t\t\t2.  Update Data \n\t\t\t\t\t\t\t\t3.  Delete Data \n\t\t\t\t\t\t\t\t4.  Display Data\n\t\t\t\t\t\t\t\t5.  Go to Previous Menu\n\n");
        printf("\t\t\t\t\t\t\t\tYour choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** ADD DATA MENU **** ******\n\n");
                printf("\t\t\t\t\t\t\t\t\t_________________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\t\t1.  Add Patients \n\t\t\t\t\t\t\t\t2.  Add Doctors \n\t\t\t\t\t\t\t\t3.  Add New Wards \n\t\t\t\t\t\t\t\t4.  Add New Medicines\n\t\t\t\t\t\t\t\t5.  Add NEw Appointments\n\t\t\t\t\t\t\t\t6.  Go to previous menu\n\n");
                printf("\n\t\t\t\t\t\t\t\tYour choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    addPatient();

                    break;

                case 2:
                    addDoctor();
                    break;

                case 3:
                    addWard();
                    break;

                case 4:
                    addMedicine();
                    break;

                case 5:
                    addAppointment();
                    break;

                case 6:
                    break;
                default:
                    printf("Invalid Input");
                }

            } while (choice != 6);

            break;

        default:
            break;

        case 2:
            do
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** UPDATE DATA MENU **** ******\n\n");
                printf("\t\t\t\t\t\t\t\t\t_________________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\t\t1.  Update Patient Record through Id \n\t\t\t\t\t\t\t\t2.  Update patient Record through Name \n\t\t\t\t\t\t\t\t3.  Update Doctors by ID \n\t\t\t\t\t\t\t\t4.  Update Ward by Id\n\t\t\t\t\t\t\t\t5.  Update Appointment By Id\n\t\t\t\t\t\t\t\t6.  Update Medicine By Id\n\t\t\t\t\t\t\t\t7.  Go to previous menu\n\n");
                printf("\n\t\t\t\t\t\t\t\tYour choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    printf("Enter Patient ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchpt_By_Id(id);
                    if (index != -1)
                    {
                        update_pt(index);
                    }
                    else
                    {
                        printf("Patient not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 2:
                {
                    system("cls");
                    printf("Enter Patient Name :");
                    char name[50];
                    scanf(" %[^\n]", name);
                    int index = searchpt_By_Name(name);
                    if (index != -1)
                    {
                        update_pt(index);
                    }
                    else
                    {
                        printf("Patient not found\n");
                        Sleep(2);
                    }
                    break;
                }

                case 3:
                {
                    system("cls");
                    printf("Enter Doctor ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchdc_By_Id(id);
                    if (index != -1)
                    {
                        update_dc(index);
                    }
                    else
                    {
                        printf("Doctor  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 4:
                {
                    system("cls");
                    printf("Enter Ward ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchwd_By_Id(id);
                    if (index != -1)
                    {
                        update_wd(index);
                    }
                    else
                    {
                        printf("Ward  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 5:
                {
                    system("cls");
                    printf("Enter Appintment ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchap_By_Id(id);
                    if (index != -1)
                    {
                        update_ap(index);
                    }
                    else
                    {
                        printf("Appointment  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 6:
                {
                    system("cls");
                    printf("Enter Medicine ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchmd_By_Id(id);
                    if (index != -1)
                    {
                        update_md(index);
                    }
                    else
                    {
                        printf("Medicnie  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 7:
                    break;

                default:
                    printf("Invalid Input");
                }

            } while (choice != 7);

        case 3:
            do
            {

                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** DELETE DATA MENU **** ******\n\n");
                printf("\t\t\t\t\t\t\t\t\t_________________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\t\t1.  Delete Patient Record through Id \n\t\t\t\t\t\t\t\t2.  Delete patient Record through Name \n\t\t\t\t\t\t\t\t3.  Delete Doctors by ID \n\t\t\t\t\t\t\t\t4.  Delete Ward by Id\n\t\t\t\t\t\t\t\t5.  Delete Appointment By Id\n\t\t\t\t\t\t\t\t6.  Delete Medicine By Id\n\t\t\t\t\t\t\t\t7.  Go to previous menu\n\n");
                printf("\n\t\t\t\t\t\t\t\tYour choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    printf("Enter Patient ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchpt_By_Id(id);
                    if (index != -1)
                    {
                        delete_pt(index);
                    }
                    else
                    {
                        printf("Patient not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 2:
                {
                    system("cls");
                    printf("Enter Patient Name :");
                    char name[50];
                    scanf(" %[^\n]", name);
                    int index = searchpt_By_Name(name);
                    if (index != -1)
                    {
                        delete_pt(index);
                    }
                    else
                    {
                        printf("Patient not found\n");
                        Sleep(2);
                    }
                    break;
                }

                case 3:
                {
                    system("cls");
                    printf("Enter Doctor ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchdc_By_Id(id);
                    if (index != -1)
                    {
                        delete_dc(index);
                    }
                    else
                    {
                        printf("Doctor  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 4:
                {
                    system("cls");
                    printf("Enter Ward ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchwd_By_Id(id);
                    if (index != -1)
                    {
                        delete_wd(index);
                    }
                    else
                    {
                        printf("Ward  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 5:
                {
                    system("cls");
                    printf("Enter Appintment ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchap_By_Id(id);
                    if (index != -1)
                    {
                        delete_ap(index);
                    }
                    else
                    {
                        printf("Appointment  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 6:
                {
                    system("cls");
                    printf("Enter Medicine ID :");
                    int id;
                    scanf("%d", &id);
                    int index = searchmd_By_Id(id);
                    if (index != -1)
                    {
                        delete_md(index);
                    }
                    else
                    {
                        printf("Medicnie  not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 7:
                    break;

                default:
                    printf("Invalid Input");
                }

            } while (choice != 7);

        case 4:
            do
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** DISPLAY DATA MENU **** ******\n\n");
                printf("\t\t\t\t\t\t\t\t\t_________________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\t\t1.  Print Patient Record   \n\t\t\t\t\t\t\t\t2.  Print Doctors Record \n\t\t\t\t\t\t\t\t3.  Print Ward Recor\n\t\t\t\t\t\t\t\t4.  Print Appointment Record\n\t\t\t\t\t\t\t\t5.  Print Medicine Record\n\t\t\t\t\t\t\t\t6.  Go to previous menu\n\n");
                printf("\n\t\t\t\t\t\t\t\tYour choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                    system("cls");

                    if (pt_count != 0)
                    {
                        for (int i = 0; i < pt_count; i++)
                        {
                            print_pt(i);
                        }
                        printf("Press Enter To Continue\n");
                        getch();
                    }
                    else
                    {
                        printf("No Patient Data found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 2:
                {
                    system("cls");

                    if (dc_count != 0)
                    {
                        for (int i = 0; i < dc_count; i++)
                        {
                            print_dc(i);
                        }
                        printf("Press Enter To Continue\n");
                        getch();
                    }
                    else
                    {
                        printf("No Doctors not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 3:
                {
                    system("cls");

                    if (wd_count != 0)
                    {
                        for (int i = 0; i < wd_count; i++)
                        {
                            print_wd(i);
                        }
                        printf("Press Enter To Continue\n");
                        getch();
                    }
                    else
                    {
                        printf("No Ward not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 4:
                {
                    system("cls");

                    if (ap_count != 0)
                    {
                        for (int i = 0; i < ap_count; i++)
                        {
                            print_ap(i);
                        }
                        printf("Press Enter To Continue\n");
                        getch();
                    }
                    else
                    {
                        printf("No Apointment Data not found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 5:
                {
                    system("cls");

                    if (md_count != 0)
                    {
                        for (int i = 0; i < md_count; i++)
                        {
                            print_md(i);
                        }
                        printf("Press Enter To Continue\n");
                        getch();
                    }
                    else
                    {
                        printf("No Medicine data found\n");
                        Sleep(2);
                    }

                    break;
                }

                case 6:
                {

                    break;
                }

                default:
                    printf("Invalid Input");
                }

            } while (choice != 6);
        }

    } while (choice != 5);
}

void search_menu()
{
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** SEARCH DATA MENU **** ******\n\n");
        printf("\t\t\t\t\t\t\t\t\t_________________________________________________\n\n\n");
        printf("\t\t\t\t\t\t\t\t1.  Search Patient Record through Id \n\t\t\t\t\t\t\t\t2.  Search patient Record through Name \n\t\t\t\t\t\t\t\t3.  Search Doctors by ID \n\t\t\t\t\t\t\t\t4.  Search Ward by Id\n\t\t\t\t\t\t\t\t5.  Search Appointment By Id\n\t\t\t\t\t\t\t\t6.  Search Medicine By Id\n\t\t\t\t\t\t\t\t7.  Go to previous menu\n\n");
        printf("\n\t\t\t\t\t\t\t\tYour choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            system("cls");
            printf("Enter patient ID : ");
            Sleep(2);
            int id;
            scanf("%d", &id);
            int index = searchpt_By_Id(id);
            if (index == -1)
            {
                printf("No Data Found ");
            }
            else
            {
                printf("Patient Record Found \n");
                printf("Enter 1 if you want to see record : ");
                int a;
                scanf("%d", &a);
                if (a == 1)
                {
                    print_pt(index);
                    printf("\nPress Enter to continue");
                    getch();
                }
            }
            break;
        }

        case 2:
        {
            system("cls");
            printf("Enter patient Name : ");
            char name[50];
            scanf("%s", &name);
            int index = searchpt_By_Name(name);
            if (index == -1)
            {
                printf("No Data Found ");
                Sleep(2);
            }
            else
            {
                printf("Patient Record Found \n");
                printf("Enter 1 if you want to see record : ");
                int a;
                scanf("%d", &a);
                if (a == 1)
                {
                    print_pt(index);
                    printf("\nPress Enter to continue");
                    getch();
                }
            }
            break;
        }
        case 3:
        {
            system("cls");
            printf("Enter Doctor ID : ");
            int id;
            scanf("%d", &id);
            int index = searchdc_By_Id(id);
            if (index == -1)
            {
                printf("No Data Found ");
                Sleep(2);
            }
            else
            {
                printf("Patient Record Found \n");
                printf("Enter 1 if you want to see record : ");
                int a;
                scanf("%d", &a);
                if (a == 1)
                {
                    print_dc(index);
                    printf("\nPress Enter to continue");
                    getch();
                }
            }
            break;
        }

        case 4:
        {
            system("cls");
            printf("Enter Ward ID : ");
            int id;
            scanf("%d", &id);
            int index = searchwd_By_Id(id);
            if (index == -1)
            {
                printf("No Data Found ");
                Sleep(2);
            }
            else
            {
                printf("Patient Record Found \n");
                printf("Enter 1 if you want to see record : ");
                int a;
                scanf("%d", &a);
                if (a == 1)
                {
                    print_wd(index);
                    printf("\nPress Enter to continue");
                    getch();
                }
            }
            break;
        }

        case 5:
        {
            system("cls");
            printf("Enter Appointment ID : ");
            int id;
            scanf("%d", &id);
            int index = searchap_By_Id(id);
            if (index == -1)
            {
                printf("No Data Found ");
                Sleep(2);
            }
            else
            {
                printf("Patient Record Found \n");
                printf("Enter 1 if you want to see record : ");
                int a;
                scanf("%d", &a);
                if (a == 1)
                {
                    print_ap(index);
                    printf("\nPress Enter to continue");
                    getch();
                }
            }
            break;
        }

        case 6:
        {
            system("cls");
            printf("Enter Medicine ID : ");
            int id;
            scanf("%d", &id);
            int index = searchmd_By_Id(id);
            if (index == -1)
            {
                printf("No Data Found ");
                Sleep(2);
            }
            else
            {
                printf("Patient Record Found \n");
                printf("Enter 1 if you want to see record : ");
                int a;
                scanf("%d", &a);
                if (a == 1)
                {
                    print_md(index);
                    printf("\nPress Enter to continue");
                    getch();
                }
            }
            break;
        }
        case 7:
            break;

        default:
            printf("Invalid Input");
            Sleep(2);
            break;
        }

    } while (choice != 7);
}

void report_menu()
{
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** REPORTS  MENU **** ******\n\n");
        printf("\t\t\t\t\t\t\t\t\t_________________________________________________\n\n\n");
        printf("\t\t\t\t\t\t\t\t1.  Admittied Patients Report By Admisson Date \n\t\t\t\t\t\t\t\t2.  Admittied Patients Report By Discharge Date \n\t\t\t\t\t\t\t\t3.  Admittied Patients Report By Doctors \n\t\t\t\t\t\t\t\t4.  Appoinments By Doctor \n\t\t\t\t\t\t\t\t5.  Appoinments By Date \n\t\t\t\t\t\t\t\t6.  Medicines By Availability Status\n\t\t\t\t\t\t\t\t7.  Total Number Of Records\n\t\t\t\t\t\t\t\t8.  Previous Menu\n\n");
        printf("\n\t\t\t\t\t\t\t\tYour choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            system("cls");
            printf("Enter Admission Date of which you want to search recorde (DD/MM/YYYY :)");
            char admission_date[20];
            scanf(" %[^\n]", admission_date);
            pt_ad_report(admission_date);
            break;
        }

        case 2:
        {
            system("cls");
            printf("Enter Discharge Date of which you want to search recorde (DD/MM/YYYY :)");
            char discharge_date[20];
            scanf(" %[^\n]", discharge_date);
            pt_dis_report(discharge_date);
            break;
        }

        case 3:
        {
            system("cls");
            printf("Enter Doctor name to search reoprt : )");
            char doctor[50];
            scanf(" %[^\n]", doctor);
            pt_by_dc(doctor);
            break;
        }

        case 4:
        {
            system("cls");
            printf("Enter Doctor Name to get report of appointment : ");
            char doctor[50];
            scanf(" %[^\n]", doctor);
            ap_by_dc(doctor);
            break;
        }
        case 5:
        {

            system("cls");
            printf("Enter Appointment Date of which youo want to get reports (DD/MM/YYYY :)");
            char appointment_date[20];
            scanf(" %[^\n]", appointment_date);
            ap_by_date(appointment_date);
            break;
        }

        case 6:
        {
            system("cls");
            printf("Enter Medicine abailibity status to get report (0 for NO.......1 For YES)");
            int availibbility;
            scanf("%d", &availibbility);
            md_by_as(availibbility);
            break;
        }

        case 7:
        {
            do
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t****** **** TOTAL RECORDS PRESENT  MENU **** ******\n\n");
                printf("\t\t\t\t\t\t\t\t\t_________________________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\t\t1.  Total Number of Patients \n\t\t\t\t\t\t\t\t2.  Total Number of Doctors \n\t\t\t\t\t\t\t\t3.  Total Number of wards \n\t\t\t\t\t\t\t\t4.  Total Medicines \n\t\t\t\t\t\t\t\t5.  Total Appintments \n\t\t\t\t\t\t\t\t6.  Go to Previous Menu \n\n");
                printf("\n\t\t\t\t\t\t\t\tYour choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    printf("\n__________________________________________\n");
                    printf("Total Number of Patients are : %d", pt_count);
                    printf("\n__________________________________________\n");
                    printf("Press Enter to Continue");
                    getch();
                    break;
                }

                case 2:
                {
                    system("cls");
                    printf("\n__________________________________________\n");
                    printf("Total Number of Doctors are : %d", dc_count);
                    printf("\n__________________________________________\n");
                    printf("Press Enter to Continue");
                    getch();
                    break;
                }

                case 3:
                {
                    system("cls");
                    printf("\n__________________________________________\n");
                    printf("Total Number of Wards are : %d", wd_count);
                    printf("\n__________________________________________\n");
                    printf("Press Enter to Continue");
                    getch();
                    break;
                }

                case 4:
                {
                    system("cls");
                    printf("\n__________________________________________\n");
                    printf("Total Number of Medicines are : %d", md_count);
                    printf("\n__________________________________________\n");
                    printf("Press Enter to Continue");
                    getch();
                    break;
                }

                case 5:
                {
                    system("cls");
                    printf("\n__________________________________________\n");
                    printf("Total Number of Appointments are : %d", ap_count);
                    printf("\n__________________________________________\n");
                    printf("Press Enter to Continue");
                    getch();
                    break;
                }

                case 6:
                    break;

                default:
                    printf("Invalid Input\n");
                    Sleep(2);
                }
            } while (choice != 6);
        }

        case 8:
            break;

        default:
            printf("Invalid Input");
        }
    } while (choice != 8);
}

int searchpt_By_Id(int id)
{
    int index, found = 0;
    for (int i = 0; i < pt_count; i++)
    {

        if (id == pt[i].id)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found == 0)
    {
        return -1;
    }

    else
    {
        return index;
    }
}

int searchpt_By_Name(char name[])
{
    int found = 0, index;
    for (int i = 0; i < pt_count; i++)
    {
        if (strcasecmp(pt[i].name, name) == 0)
        {
            index = i;
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void addPatient()
{

    system("cls");
    printf("      ****** **** ADD PATIENTS MENU **** ******\n\n");
    printf("_________________________________________________\n\n");
    printf("Enter Patient's Details:\n\n");
    if (pt_count == 100)
    {
        puts("Patient List is Full");
    }

    else
    {

        printf("Enter Patient Id  : ");
        int id;
        scanf("%d", &id);

        int found = searchpt_By_Id(id);
        if (found == -1)
        {
            pt[pt_count].id = id;
            printf("Enter Patient Name  : ");
            scanf(" %[^\n]", pt[pt_count].name);

            printf("Enter Patient Gender M/F  : ");
            scanf(" %c", &pt[pt_count].gender);

            printf("Enter Patient age  : ");
            scanf("%d", &pt[pt_count].age);

            printf("Enter Patient Disease  : ");
            scanf(" %[^\n]", pt[pt_count].disease);

            printf("Enter Patient Bed No  : ");
            scanf("%d", &pt[pt_count].bed_no);

            printf("Enter Patient Doctor id from the below doctors   \n");
            for (int i = 0; i < dc_count; i++)
            {
                printf("%d.  %s  (id=%d) \n", i + 1, dc[i].name, dc[i].id);
            }

            scanf("%d", &pt[pt_count].dc_id);

            for (int i = 0; i < dc_count; i++)
            {
                if (pt[pt_count].dc_id == dc[i].id)
                {

                    strcpy(pt[pt_count].dc_name, dc[i].name);
                    break;
                }
            }

            printf("Choose patient ward by entering Patient Ward id from below\n");
            for (int i = 0; i < wd_count; i++)
            {
                printf("%d.  %s  (id=%d) \n", i + 1, wd[i].name, wd[i].id);
            }

            scanf("%d", &pt[pt_count].wd_id);
            for (int i = 0; i < wd_count; i++)
            {
                if (pt[pt_count].wd_id == wd[i].id)
                {
                    strcpy(pt[pt_count].ward, wd[i].name);
                    strcpy(pt[pt_count].ward, wd[i].name);
                    break;
                }
            }
            printf("Enter Patient Admission Date(DD/MM/YYYY)  : ");
            scanf(" %[^\n]", pt[pt_count].admission_date);

            printf("Enter Patient Admission Status(1 for currently admittied ..... 0 for not currently admitted)  : ");
            scanf("%d", &pt[pt_count].admision_status);

            printf("Enter Patient Discharge Date(DD/MM/YYYY)   give null if currently admitted: ");
            scanf(" %[^\n]", pt[pt_count].discharge_date);
            pt_count++;

            printf("Data Added Successfully.\n");
            Sleep(2);
        }
        else
        {
            printf("Patient with this id Already Exist\n");
            Sleep(2);
        }
    }
}
void update_pt(int index)
{
    printf("Enter Patient Name  : ");
    scanf(" %[^\n]", pt[index].name);

    printf("Enter Patient Gender M/F  : ");
    scanf(" %c", &pt[index].gender);

    printf("Enter Patient age  : ");
    scanf("%d", &pt[index].age);

    printf("Enter Patient Disease  : ");
    scanf(" %[^\n]", pt[index].disease);

    printf("Enter Patient Bed No  : ");
    scanf("%d", &pt[index].bed_no);

    printf("Enter Patient Doctor id from the below doctors   \n");
    for (int i = 0; i < dc_count; i++)
    {
        printf("%d  .%s  (id=%d) \n", i + 1, dc[i].name, dc[i].id);
    }

    scanf("%d", &pt[index].dc_id);

    for (int i = 0; i < dc_count; i++)
    {
        if (pt[pt_count].dc_id == dc[i].id)
        {

            strcpy(pt[index].dc_name, dc[i].name);
            break;
        }
    }

    printf("Choose patient ward by entering Patient Ward id from below\n");
    for (int i = 0; i < wd_count; i++)
    {
        printf("%d  .%s  (id=%d) \n", i + 1, wd[i].name, wd[i].id);
    }

    scanf("%d", &pt[index].wd_id);
    for (int i = 0; i < wd_count; i++)
    {
        if (pt[pt_count].wd_id == wd[i].id)
        {

            strcpy(pt[index].ward, wd[i].name);
            break;
        }
    }
    printf("Enter Patient Admission Date(DD/MM/YYYY)  : ");
    scanf(" %[^\n]", pt[index].admission_date);

    printf("Enter Patient Discharge Date(DD/MM/YYYY)  : ");
    scanf(" %[^\n]", pt[index].discharge_date);

    printf("Data Updated  Successfully.\n");
    Sleep(2);
}

void delete_pt(int index)
{
    for (int i = index; i < pt_count; i++)
    {
        pt[i].id = pt[i + 1].id;
        strcpy(pt[i].name, pt[i + 1].name);
        pt[i].gender = pt[i + 1].gender;
        pt[i].age = pt[i + 1].age;
        pt[i].bed_no = pt[i + 1].bed_no;
        strcpy(pt[i].dc_name, pt[i + 1].dc_name);
        pt[i].dc_id = pt[i + 1].dc_id;
        strcpy(pt[i].ward, pt[i + 1].ward);
        pt[i].wd_id = pt[i + 1].wd_id;

        strcpy(pt[i].admission_date, pt[i + 1].admission_date);
        strcpy(pt[i].discharge_date, pt[i + 1].discharge_date);
    }
    pt_count--;
    printf("Data Deleted Successfully.\n");
    Sleep(2);
}

void print_pt(int index)
{
    printf("\n_________________________________\n");
    printf("Patient ID  : %d\n", pt[index].id);
    printf("Patient Name  : %s\n", pt[index].name);
    printf("Patient Gender  : %c\n", pt[index].gender);
    printf("Patiend disease is : %s\n", pt[index].disease);
    printf("Patient Age  : %d\n", pt[index].age);
    printf("Patient Bed No  : %d\n", pt[index].bed_no);
    printf("Patient Doctor Name  : %s\n", pt[index].dc_name);

    printf("Patient Ward  : %s\n", pt[index].ward);

    printf("Patient Admission Date  : %s\n", pt[index].admission_date);
    printf("Patient Discharge Date  : %s\n", pt[index].discharge_date);
    printf("_________________________________\n");
}
void addDoctor()
{

    system("cls");
    printf("      ****** **** ADD DOCTORS MENU **** ******\n\n");
    printf("_________________________________________________\n\n");
    printf("Enter Doctor's Details:\n\n");

    if (dc_count == 10)
    {
        puts("Doctor list is already full\n");
    }

    else
    {
        int id, found;
        printf("Enter Doctor Id :");
        scanf("%d", &id);
        found = searchdc_By_Id(id);
        if (found == -1)
        {
            dc[dc_count].id = id;
            printf("Enter Doctor Name :");
            scanf(" %[^\n]", dc[dc_count].name);

            printf("Enter Doctor Gender (M/F):");
            scanf(" %c", &dc[dc_count].gender);

            printf("Enter Doctor Specialization : ");
            scanf("%s", &dc[dc_count].speacialization);
            dc_count++;
            printf("Data Added Successfully.\n");
            Sleep(2);
        }
        else
        {
            printf("Doctor with same id already exist");
            Sleep(2);
        }
    }
}

int searchdc_By_Id(int id)
{
    int found = 0, index;
    for (int i = 0; i < 10; i++)
    {
        if (id == dc[i].id)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void update_dc(int index)
{
    printf("Enter Doctor Name :");
    scanf(" %[^\n]", dc[index].name);

    printf("Enter Doctor Gender (M/F):");
    scanf(" %c", &dc[index].gender);

    printf("Enter Doctor Specialization : ");
    scanf("%s", &dc[index].speacialization);

    printf("Data Updated Successfully.\n");
    Sleep(2);
}

void delete_dc(int index)
{
    for (int i = index; i < dc_count; i++)
    {
        dc[i].id = dc[i + 1].id;
        strcpy(dc[i].name, dc[i + 1].name);
        dc[i].gender = dc[i + 1].gender;
        strcpy(dc[i].speacialization, dc[i + 1].speacialization);
    }
    printf("Data Deleted Successfully\n");
    dc_count--;
    Sleep(2);
}

void print_dc(int index)
{
    printf("\n_________________________________\n");
    printf("Doctor id is : %d", dc[index].id);
    printf("\nDoctor Name is : %s", dc[index].name);
    printf("\nDoctor Gender is : %c", dc[index].gender);
    printf("\nDoctor Specialization is : %s", dc[index].speacialization);
    printf("\n_________________________________\n");
}

void addMedicine()
{
    system("cls");
    printf("      ****** **** ADD MEDICINES MENU **** ******\n\n");
    printf("_________________________________________________\n\n");
    printf("Enter Medicine's Details:\n\n");

    if (md_count == 100)
    {
        puts("Medicine list is already full\n");
    }

    else
    {
        int id;
        printf("Enter Medincine Id: ");
        scanf("%d", &id);
        if (searchmd_By_Id(id) == -1)
        {
            md[md_count].id = id;
            printf("Enter Medicine Name: ");
            scanf(" %[^\n]", md[md_count].name);

            printf("Enter Medicine Price: ");
            scanf("%d", &md[md_count].price);

            printf("Enter Medicine Availabilty Status(o for no .....1 for yes): ");
            scanf("%d", &md[md_count].availibility_status);

            printf("\nData has been added successfully!");
            md_count++;
            Sleep(2);
        }
        else
        {
            printf("Medicine with this id Already exist");
            Sleep(2);
        }
    }
}

int searchmd_By_Id(int id)
{
    int found = 0, index;
    for (int i = 0; i < 100; i++)
    {
        if (id == md[i].id)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found == 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void update_md(int index)
{
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]", md[index].name);

    printf("Enter Medicine Price: ");
    scanf("%d", &md[index].price);

    printf("Enter Medicine Availabilty Status(o for no .....1 for yes): ");
    scanf("%d", &md[index].availibility_status);

    printf("\nData has been updated successfully!");

    Sleep(2);
}

void delete_md(int index)
{
    for (int i = index; i < md_count; i++)
    {
        md[i].id = md[i + 1].id;
        strcpy(md[i].name, md[i + 1].name);
        md[i].price = md[i + 1].price;
        md[i].availibility_status = md[i + 1].availibility_status;
    }
    printf("Recorde Deleted Successfully\n");
    md_count--;
    Sleep(2);
}
void print_md(int index)
{
    printf("\n_________________________________\n");
    printf("Medicine ID: %d\n", md[index].id);
    printf("Medicine Name: %s\n", md[index].name);
    printf("Medicine Price: %d\n", md[index].price);
    printf("Medicine Availabilty Status(0 means NO.....1 means yes) : %d\n", md[index].availibility_status);
    printf("\n_________________________________\n");
}
void addWard()
{
    system("cls");
    printf("      ****** **** ADD WARD MENU **** ******\n\n");
    printf("_________________________________________________\n\n");
    printf("Enter Ward's Details:\n\n");

    if (wd_count == 10)
    {
        puts("Ward list is already full\n");
    }

    else
    {
        int id;
        printf("Enter Ward Id: ");
        scanf("%d", &id);
        if (searchwd_By_Id(id) == -1)
        {
            wd[wd_count].id = id;
            printf("Enter Ward Name: ");
            scanf(" %[^\n]", wd[wd_count].name);

            printf("Enter ward Capacity: ");
            scanf("%d", &wd[wd_count].capacity);

            printf("\nData has been added successfully!");
            wd_count++;
            Sleep(2);
        }
        else
        {
            printf("Ward with this id Already exist");
            Sleep(2);
        }
    }
}

int searchwd_By_Id(int id)
{
    int found = 0, index;
    for (int i = 0; i < wd_count; i++)
    {
        if (id == wd[i].id)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found == 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void update_wd(int index)
{
    printf("Enter Ward Name: ");
    scanf(" %[^\n]", wd[index].name);

    printf("Enter ward Capacity: ");
    scanf("%d", &wd[index].capacity);

    printf("\nData has been updated successfully!");

    Sleep(2);
}
void delete_wd(int index)
{
    for (int i = index; i < wd_count; i++)
    {
        wd[i].id = wd[i + 1].id;
        strcpy(wd[i].name, wd[i + 1].name);
        wd[i].capacity = wd[i + 1].capacity;
    }
    printf("Record Deleted Successfully\n");
    wd_count--;
    Sleep(2);
}

void print_wd(int index)
{
    printf("\n_________________________________\n");
    printf("Ward ID is : %d\n", wd[index].id);
    printf("Ward Name is : %s\n", wd[index].name);
    printf("Ward Capacity is : %d\n", wd[index].capacity);
    printf("\n_________________________________\n");
}
void addAppointment()
{
    system("cls");
    printf("      ****** **** ADD APPOINTMENT MENU **** ******\n\n");
    printf("_________________________________________________\n\n");
    printf("Enter Appointment's Details:\n\n");

    if (ap_count == 500)
    {
        puts("Ward list is already full\n");
    }

    else
    {
        int id;
        printf("Enter Appointment Id: ");
        scanf("%d", &id);
        if (searchap_By_Id(id) == -1)
        {
            ap[ap_count].id = id;
            printf("Enter Patint Name: ");
            scanf(" %[^\n]", ap[ap_count].pt_name);

            printf("Enter Patient Doctor id from the below doctors to choose doctor   \n");
            for (int i = 0; i < dc_count; i++)
            {
                printf("%d.  %s  (id=%d) \n", i + 1, dc[i].name, dc[i].id);
            }

            scanf("%d", &ap[ap_count].doctor_id);

            for (int i = 0; i < dc_count; i++)
            {
                if (ap[ap_count].doctor_id == dc[i].id)
                {
                    strcpy(ap[wd_count].dc_name, dc[i].name);

                    break;
                }
            }

            printf("Enter Reason of Visit: ");
            scanf(" %[^\n]", ap[ap_count].reason);

            printf("Enter Date of Visit(DD/MM.YYYY): ");
            scanf(" %[^\n]", ap[ap_count].date);

            printf("\nData has been added successfully!");
            ap_count++;
            Sleep(2);
        }
        else
        {
            printf("Appointment with this id Already exist");
            Sleep(2);
        }
    }
}

int searchap_By_Id(int id)
{
    int found = 0, index;
    for (int i = 0; i < ap_count; i++)
    {
        if (id == ap[i].id)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found == 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void update_ap(int index)
{
    printf("Enter Patint Name: ");
    scanf(" %[^\n]", ap[index].pt_name);

    printf("Enter Patient Doctor id from the below doctors to choose doctor   \n");
    for (int i = 0; i < dc_count; i++)
    {
        printf("%d  .%s  (id=%d) \n", i + 1, dc[i].name, dc[i].id);
    }

    scanf("%d", &ap[index].doctor_id);

    for (int i = 0; i < dc_count; i++)
    {
        if (ap[index].doctor_id == dc[i].id)
        {
            strcpy(ap[index].dc_name, dc[i].name);

            break;
        }
    }

    printf("Enter Reason of Visit: ");
    scanf(" %[^\n]", ap[index].reason);

    printf("Enter Date of Visit(DD/MM.YYYY): ");
    scanf(" %[^\n]", ap[index].date);

    printf("\nData has been updated successfully!");

    Sleep(2);
}

void delete_ap(int index)
{
    for (int i = index; i < ap_count; i++)
    {
        ap[i].id = ap[i + 1].id;
        strcpy(ap[i].pt_name, ap[i + 1].pt_name);
        ap[i].doctor_id = ap[i + 1].doctor_id;
        strcpy(ap[i].dc_name, ap[i + 1].dc_name);
        strcpy(ap[i].reason, ap[i + 1].reason);
        strcpy(ap[i].date, ap[i + 1].date);
    }
    printf("Data Deleted Successfully\n");
    ap_count--;
    Sleep(2);
}

void print_ap(int index)
{
    printf("\n_________________________________\n");
    printf("Appointment id is : %d\n", ap[index].id);
    printf("Name of patient is : %s\n", ap[index].pt_name);
    printf("Doctor name is : %s\n", ap[index].dc_name);
    printf("Reason of visit is : %s\n", ap[index].reason);
    printf("Date of visit is %s\n", ap[index].date);
    printf("\n_________________________________\n");
}

void pt_ad_report(char ad_date[])
{
    int a = 0;
    for (int i = 0; i < pt_count; i++)
    {
        if (strcmp(ad_date, pt[i].admission_date) == 0)
        {
            printf("\n_______________________________\n");
            printf("Patient id is : %d\n", pt[i].id);
            printf("Name of patient is : %s\n", pt[i].name);
            printf("Age of patient is : %d\n", pt[i].age);
            printf("Doctor of the patient is : %s", pt[i].dc_name);
            printf("Ward of the patient is : %s", pt[i].ward);
            printf("Diseae of the Patient is : %s", pt[i].disease);
            printf("\n_______________________________\n");
            a = 1;
        }
    }

    if (a == 0)
    {
        printf("No patient admitted on this date\n");
    }
    printf("Press Enter to Continue\n");
    getch();
}

void pt_dis_report(char dis_date[])
{
    int a = 0;
    for (int i = 0; i < pt_count; i++)
    {
        if (strcmp(dis_date, pt[i].discharge_date) == 0)
        {
            printf("\n_______________________________\n");
            printf("Patient id is : %d\n", pt[i].id);
            printf("Name of patient is : %s\n", pt[i].name);
            printf("Age of patient is : %d\n", pt[i].age);
            printf("Doctor of the patient is : %s", pt[i].dc_name);
            printf("Ward of the patient is : %s", pt[i].ward);
            printf("Diseae of the Patient is : %s", pt[i].disease);
            printf("\n_______________________________\n");
            a = 1;
        }
    }

    if (a == 0)
    {
        printf("No patient Discharged on this date\n");
    }
    printf("Press Enter to Continue\n");
    getch();
}

void pt_by_dc(char doc[])
{
    int a = 0;
    for (int i = 0; i < pt_count; i++)
    {
        if (strcasecmp(doc, pt[i].dc_name) == 0 && pt[i].admision_status == 1)
        {
            printf("\n_______________________________\n");
            printf("Patient id is : %d\n", pt[i].id);
            printf("Name of patient is : %s\n", pt[i].name);
            printf("Age of patient is : %d\n", pt[i].age);
            printf("Doctor of the patient is : %s", pt[i].dc_name);
            printf("Ward of the patient is : %s", pt[i].ward);
            printf("Diseae of the Patient is : %s", pt[i].disease);
            printf("Admission Date of the patient is : %s", pt[i].admission_date);
            printf("Discharge of the patient is : %s", pt[i].discharge_date);
            printf("Patient is currently admitted");
            printf("\n_______________________________\n");
            a = 0;
        }
        if (a == 0)
        {
            printf("No patient of this doctor\n");
        }
    }
    printf("Press Enter to Continue\n");
    getch();
}
void ap_by_dc(char doc[])
{
    int a = 0;
    for (int i = 0; i < ap_count; i++)
    {
        if (strcasecmp(doc, ap[i].dc_name) == 0)
        {
            printf("\n_______________________________\n");
            printf("Appointment id is : %d\n", ap[i].id);
            printf("Name of patient is : %s\n", ap[i].pt_name);
            printf("Name of doctor is :", ap[i].dc_name);
            printf("Reson of appointment is : %s", ap[i].reason);
            printf("Date of appointment is : %s", ap[i].date);
            printf("\n_______________________________\n");
            a = 0;
        }

        if (a == 0)
        {
            printf("No appointment of this doctor \n");
        }
    }
    printf("Press Enter to Continue\n");
    getch();
}

void ap_by_date(char date[])
{
    int i = 0, a = 0;
    for (i; i < ap_count; i++)
    {
        if (strcmp(date, ap[i].date) == 0)
        {
            printf("\n_______________________________\n");
            printf("Appointment id is : %d\n", ap[i].id);
            printf("Name of patient is : %s\n", ap[i].pt_name);
            printf("Name of doctor is :", ap[i].dc_name);
            printf("Reson of appointment is : %s", ap[i].reason);
            printf("Date of appointment is : %s", ap[i].date);
            printf("\n_______________________________\n");
            a = 0;
        }

        if (a == 0)
        {
            printf("No appointment of this doctor on this date\n");
        }
    }
    printf("Press Enter to Continue\n");
    getch();
}

void md_by_as(int availability)
{
    int a = 0;
    for (int i = 0; i < md_count; i++)
    {
        if (md[i].availibility_status == availability)
        {
            printf("\n_______________________________\n");
            printf("Id of the Medicine is %d :", md[i].id);
            printf("Name of the Medicine is %s :", md[i].name);
            printf("Price of the Medicine is : %d ", md[i].price);
            printf("Availability of the Medicine is : %d(0 for No 1 For Yes) ", md[i].availibility_status);
            printf("\n_______________________________\n");
            a = 1;
        }

        if (a == 0)
        {
            printf("No medicine is available in record with availibity status you provided\n");
        }
    }

    printf("Press Enter to Continue");
    getch();
}

void feed_data()
{
    FILE *fp = fopen("patients.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%d\n", pt_count);
    for (int i = 0; i < pt_count; i++)
    {
        fprintf(fp, "%d,%s,%c,%d,%s,%d,%s,%d,%s,%d,%s,%s\n",
                pt[i].id, pt[i].name, pt[i].gender, pt[i].age,
                pt[i].disease, pt[i].bed_no, pt[i].dc_name, pt[i].dc_id,
                pt[i].ward, pt[i].wd_id, pt[i].admission_date, pt[i].discharge_date);
    }
    fclose(fp);

    fp = fopen("doctors.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%d\n", dc_count);
    for (int i = 0; i < dc_count; i++)
    {
        fprintf(fp, "%d,%s,%c,%s\n",
                dc[i].id, dc[i].name, dc[i].gender, dc[i].speacialization);
    }
    fclose(fp);

    fp = fopen("wards.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%d\n", wd_count);
    for (int i = 0; i < wd_count; i++)
    {
        fprintf(fp, "%d,%s,%d\n",
                wd[i].id, wd[i].name, wd[i].capacity);
    }
    fclose(fp);

    fp = fopen("medicines.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%d\n", md_count);
    for (int i = 0; i < md_count; i++)
    {
        fprintf(fp, "%d,%s,%d,%d\n",
                md[i].id, md[i].name, md[i].price, md[i].availibility_status);
    }
    fclose(fp);

    fp = fopen("appointments.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp, "%d\n", ap_count);
    for (int i = 0; i < ap_count; i++)
    {
        fprintf(fp, "%d,%s,%d,%s,%s,%s\n",
                ap[i].id, ap[i].pt_name, ap[i].doctor_id, ap[i].dc_name,
                ap[i].reason, ap[i].date);
    }
    fclose(fp);
}

void fetch_data()
{
    FILE *fp = fopen("patients.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fscanf(fp, "%d\n", &pt_count);
    for (int i = 0; i < pt_count; i++)
    {
        fscanf(fp, "%d,%[^,],%c,%d,%[^,],%d,%[^,],%d,%[^,],%d,%[^,],%d,%[^,]\n",
               &pt[i].id, pt[i].name, &pt[i].gender, &pt[i].age, pt[i].disease,
               &pt[i].bed_no, pt[i].dc_name, &pt[i].dc_id, pt[i].ward,
               &pt[i].wd_id, pt[i].admission_date, &pt[i].admision_status, pt[i].discharge_date);
    }
    fclose(fp);

    fp = fopen("doctors.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fscanf(fp, "%d\n", &dc_count);
    for (int i = 0; i < dc_count; i++)
    {
        fscanf(fp, "%d,%[^,],%c,%[^\n]\n",
               &dc[i].id, dc[i].name, &dc[i].gender, dc[i].speacialization);
    }
    fclose(fp);

    fp = fopen("wards.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fscanf(fp, "%d\n", &wd_count);
    for (int i = 0; i < wd_count; i++)
    {
        fscanf(fp, "%d,%[^,],%d\n",
               &wd[i].id, wd[i].name, &wd[i].capacity);
    }
    fclose(fp);

    fp = fopen("medicines.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fscanf(fp, "%d\n", &md_count);
    for (int i = 0; i < md_count; i++)
    {
        fscanf(fp, "%d,%[^,],%d,%d\n",
               &md[i].id, md[i].name, &md[i].price, &md[i].availibility_status);
    }
    fclose(fp);

    fp = fopen("appointments.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fscanf(fp, "%d\n", &ap_count);
    for (int i = 0; i < ap_count; i++)
    {
        fscanf(fp, "%d,%[^,],%d,%[^,],%[^,],%[^\n]\n",
               &ap[i].id, ap[i].pt_name, &ap[i].doctor_id, &ap[i].dc_name,
               ap[i].reason, ap[i].date);
    }
    fclose(fp);
}
