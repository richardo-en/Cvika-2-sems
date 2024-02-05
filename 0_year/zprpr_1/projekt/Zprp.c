#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
|¯¯¯¯|  |   |  | |¯¯¯¯ |  / 
|___\|  |   |  | |     |_/
     \_ |___|  | |____ |  \     Dokumentacia
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
Vopred sa ospravedlnujem za gramatiku obcas to moze vypichnut oci :)

Funkcie check su kontrolne funkcie ktore kontroluju ako aj vstup od pouzivatela tak aj vstup suboru. Kontroluju Spravnost napisania mena,
datum , roky, regiony a spravnost formatu testov. Program sa moze zdat byt trocha pomalsi ale je tu siroka skala veci ktora je osetrena.

Funkcie get vracaju spat hodnoty alebo ukladaju zvycajne do globalnych premennych nejake hodnoty. Pokial by nejaka funkcia vracal nespravny
vystup je dost pravdepodobne ze staci pouzit memset alebo fflush pred citanim vstupu.

Osetrene: kontrolujem pohlavie ci je m alebo f, kontroluje datum pri vytarani zaznamu a citani suboru, ci sa da vobec taky mesiac a rok zadat a ci je k nemu napisany
vhodny pocet dni. Aj ku konkretnym mesiacom ako napr ze feb. moze mat max 29 dni a ze januar moze mat max 31 dni etc.
V regione nemoze byt chyba musi byt napisany jednoznacne...uvedene nizsie pri check_region() formaty regionu. Takisto sa kontruluje
aj format testov vo vsetkych moznostiach zlych vstupov by mal byt osetreny a mozne je zadat maximalne 100.00 bodov.

K funkciam su napisane anglicke komentare som tak zvyknuty z roboty ¯\_( ͠° ͟ʖ °͠ )_/¯ .Z internetu som nekopiroval nic len som sa inspiroval structom z
https://github.com/portfoliocourses/c-example-code/blob/main/csv_to_struct_array.c ale v konecnom dosledku som ho niekolko krat prerabal.
Takisto som si vyhladal funkcie ako atof atoi etc. ako sa pouzivaju a ako funguju tak to sa hadam za plagiatorstvo nepovazuje.

Prajem prijemnu zabavu pri testovani :)
*/

void check_test();
void check_date();
void check_region();
struct Student {
    char name[50];
    char gender;
    char year[5];
    char month[3];
    char date[3];
    char g[2];
    char region[30];
    double result[6];
};

struct Student students[100];
int records = 0 , highest_year = 0 , lowest_year = 2023 , was_printed = 0;
char current_gender[5] , controll_name[50];

//checking if test's are written right
void check_file_test(){
    FILE * data;
    data = fopen("studenti.csv", "r");
    int count = 0, index = 0 , semicolumn_count = 0;
    char test_result[42] , c;
    if (data == NULL) {
        printf("Chyba pri otvarani suboru\n");
        return;
    }
    //reseting string before reading
    memset(test_result , 0 , sizeof(test_result));
    do
    {
        c = (char)fgetc(data);
        if (count == 4){
            if (c != '\n'){
                test_result[index] = c;
                index++;
            }else{
                check_test(test_result , 1);
                index = 0;
                count = 0;
                memset(test_result , 0 , sizeof(test_result));
            }
        }else if(c == ';'){
            count++;
        }
    } while (c != EOF);
    fclose(data);
}

//getting values before evry action
void get_vals() {
    //reseting struct
    memset(students , 0 , sizeof(students));
    //checking test's
    check_file_test();
    char test_correctness[42] , date_correctness[11] , region_correctness[20];
    records = 0 , highest_year = 0 , lowest_year = 2023;
    int asd = 0;
    FILE * data;
    data = fopen("studenti.csv", "r");

    if (data == NULL) {
        printf("\nStala sa chyba pri citani suboru. Pravdepodobne sa neda takyto subor otvorit.");
        return;
    }
    int read = 0;
    do {
        read = fscanf(data,
            "%49[^;];%c;%5[^/]/%3[^/]/%3[^;];%30[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
            students[records].name, &
            students[records].gender, &
            students[records].year, &
            students[records].month, &
            students[records].date, &
            students[records].region, &
            students[records].result[0], &
            students[records].result[1], &
            students[records].result[2], &
            students[records].result[3], &
            students[records].result[4], &
            students[records].result[5]);

        if (read == 12) { 
            //checks for gender           
            if (students[records].gender != 'f'){
                if (students[records].gender != 'm'){                
                    printf("Pohlavie je zle zadane subor sa neda precitat");
                    break;
                }
            }

            //check date
            snprintf(date_correctness , 11 , "%s/%s/%s" , students[records].year , students[records].month , students[records].date);
            check_date(date_correctness , 1);

            //check region
            snprintf(region_correctness , 20 , "%s" , students[records].region);
            check_region(region_correctness , 1);
            
            //check if isn't in file same name
            if (records > 0){
                for (int a = 0; a < records; a++){
                    if (strcmp(students[a].name , students[records].name) == 0){
                        printf("\nNasla sa zhoda 2 zaznamov s rovankym menom -> \"%s\". S takymto suborom nieje mozne pracovat. Riadok: %d" , students[records].name , records +1);
                        exit(1);
                    }
                }
            }
        
            //saving lowest and highest year for later functions
            if (atoi(students[records].year) < lowest_year){
                lowest_year = atoi(students[records].year);
            }else if(atoi(students[records].year) > highest_year){
                highest_year = atoi(students[records].year);
            }
            
            //tracking number of records
            records++;
        }
        if (ferror(data)) {
            printf("Stala sa chyba pri citani dat! Subor sa zacal citat ale zastavil na riadku %d.\n", (records + 1));
            exit(1);
        }
    } while (!feof(data));
    fclose(data);
    if (was_printed == 0){
        printf("\nSubor sa podarilo precitat uspesne.");
        was_printed = 1;
    }
    
    return;
}

//printing gender
void get_gender(char type_of_gen) {
    if (type_of_gen == 'm') {
        strcpy(current_gender, "muz");
    } else if (type_of_gen == 'f') {
        strcpy(current_gender, "zena");
    } else {
        printf("\nMame iba 2 pohlavia!!!");
    }
}

//getting number of record based on last name
void get_last_name(int *record_id , int from_func){
    *record_id = records +1;
    int space_count = 0 , space_controll_count = 0 , index = 0 , second_name_spaces = 0;
    char last_name[50] , record_name[50] , second_name[50];

    while (1)
    {
        //if you are selecting name else comparing names in csv
        if (from_func == 0)
        {
            printf("\nZadajte priezvisko(posledne meno):\n");
            scanf(" %s", &last_name);
        
        }else{
            //copying name to check if in file isnt same name
            strcpy(last_name , controll_name);
            memset(second_name,0,sizeof(second_name));

            //counting spaces
            for (int a = 0; a < strlen(controll_name); a++){
                if (controll_name[a] == 32){
                    second_name_spaces++;
                }
            }
            //copying last name to comparness
            for (int s = 0; s < strlen(controll_name); s++){
                if (second_name_spaces == space_controll_count){
                    second_name[index] = controll_name[s];
                    index++;
                }else if (controll_name[s] == 32){
                    space_controll_count++;
                }
            }
        }

        //comparing if selected name isn't already in csv file
        for (int i = 0; i < records; i++){
            //reset values
            memset(record_name,0,sizeof(record_name));
            space_count = 0 , space_controll_count = 0 , index = 0;
    
            //get count of spaces from name in struct
            for (int a = 0; a < strlen(students[i].name); a++){
                if (students[i].name[a] == 32){
                    space_count++;
                }
            }

            //extract last name from record name to record_name
            for (int s = 0; s < strlen(students[i].name); s++){
                if (space_controll_count == space_count){
                    record_name[index] = students[i].name[s];
                    index++;
                }else if (students[i].name[s] == 32){
                    space_controll_count++;
                }
            }

            //compare names base on from whitch function is this called. if exist record with same name save id to pointer
            if (from_func == 0){
                if (strcmp(record_name , last_name) == 0){
                    *record_id = i;
                    break;
                }
            }else{
                if (strcmp(record_name , second_name) == 0){
                    *record_id = i;
                    break;
                } 
            }
            
        }
        //if same name wasnt found save into pointer records+1 ....that means record doesnt exist 
        if (*record_id != records + 1){
            break;
        }else{
            if (from_func == 1){
                *record_id = records + 1;
                break;
            }  
            printf("\nTaketo meno nemame v zazname.");
        }
    }
}

//Controlls rightness of written name
void check_name() {
    int controll_point = 1, error_point = 0, count = 0 , space_count = 0 , controll_space_count = 0 , index = 0 , record_id = 0;
    char last_name[50];

    //check if isnt whole name in csv file
    while (controll_point == 1) {
        for (int a = 0; a < records; a++) {
            if (strcmp(controll_name, students[a].name) == 0 && error_point == 0) {
                printf("\nToto meno uz je v databaze\n");
                error_point = 1;
            }
        }
        //checks if is first character capital if in name isn't anything other than letters and if there is space next cahracter must be capital too
        for (int i = 0; i < strlen(controll_name); i++) {
            if (error_point == 0){
                if(i == 0 && (controll_name[i] < 65 || controll_name[i] > 90) && error_point == 0) {
                    error_point = 1;
                }else if(controll_name[i - 1] == 32 && error_point == 0 && (controll_name[i] < 65 || controll_name[i] > 90)) {
                    error_point = 1;
                }else {
                    if ((controll_name[i] == 32) || (controll_name[i-1] == 32)) {
                        if (controll_name[i] == 32) {
                            count++;
                        }
                        continue;
                    }else if((controll_name[i] > 122) || (controll_name[i] < 97)){
                        if (i != 0){
                            error_point = 1;
                        }
                    }
                }
            }
        }

        //extract last name
        for (int i = 0; i < strlen(controll_name); i++){
            if (controll_name[i] == 32)
            {
                controll_space_count++;
            }else if (count == controll_space_count)
            {
                last_name[index] = controll_name[i];
                index++;
            }

            //check if last name isnt in database
            get_last_name(&record_id , 1);
            //if record exist return error
            if (record_id != records + 1)
            {
                printf("\nOsoba s takymto priezviskom uz je v zazname!\n");
                error_point = 1;
            }
        }
        //if there is error ask again for name else leave function
        if (error_point == 1 || count < 1) {
            printf("Zadajte krstne meno na zaciatku s velkym , v mene sa nesmu nachadzat ine znaky ako male pismena. Po kazdej medzere sa musi meno zacinat velkym pismenom:\n");
            fflush(stdin);
            gets(controll_name);

            error_point = 0;
            count = 0;
        } else {
            controll_point = 0;
        }
    }
}

//checks gender if input is wrong ask for another input
void check_gender(char * gender) {
    int gender_correct = 0;
    while (gender_correct == 0) {
        if ( * gender == 'm' || * gender == 'f') {
            gender_correct = 1;
        } else {
            printf("\nNespravny vstup zadajte f pre zenu alebo m pre muza: \n");
            scanf(" %c", gender);
        }
    }
}

//checks if all regions are written or inputed right
void check_region(char new_region[20] , int from_func) {
    int region_correct = 0;
    char region_list[8][40] = {"bratislavsky","trnavsky","trenciansky","nitriansky","zilinsky","banskobystricky","presovsky","kosicky"};
    //if region correct is true break
    while (region_correct == 0) {
        for (int i = 0; i < 8; i++) {
            //checks if region is in list
            if (strcmp(new_region, region_list[i]) == 0) {
                region_correct = 1;
                break;
            }
        }
        //if region isn't in list ask for another input
        if (region_correct == 0) {
            //if checking region in csv file return error
            if (from_func == 1){
                printf("Zle zadany region v subore, takyto subor sa neda citat. Chyba je v regione %s na riadku %d." ,new_region , records +1);
                exit(1);
            }
            //print options
            printf("Zadajte jeden s nasledovnych regionov:\n");
            for (int i = 0; i < 8; i++) {
                printf(" %s\n", region_list[i]);
            }
            fflush(stdin);
            gets(new_region);
        }
    }
}

//checks if test formatting is right
void check_test(char test[42] , int from_func) {
    int test_correct = 0, index = 0 , char_count= 0 , count = 0 , semi_column_count = 0;
    char test_num[6];
    float number = 0.0;
    memset(test_num , 0 , sizeof(test_num));
    while (test_correct == 0) {
        //lowest and highest lenght of test's
        if (strlen(test) >= 35 && strlen(test) <= 41) {
            for (int i = 0; i < strlen(test); i++){
                if (test[i] == ';'){
                   semi_column_count++;
                }
            }
            //if there is right amount of test's
            if (semi_column_count == 5)
            {
                while (char_count < strlen(test)+1){   
                    //check every test correctness
                    if(test[char_count] == ';' || (strlen(test_num) > 4 && count == 5)){
                        number = atof(test_num);
                        if (strlen(test_num) < 5){
                            printf("\nZle zadany test. Test musi byt v tvare xx.xx");
                            break;
                        }else if (test_num[3] == '.' && number != 100.00){
                            printf("\nVysledok nemoze byt vacsi ako 100.00. Ked vysledok nieje 100.00 tak nemozte zapisat 5 ciferne cislo");
                            break;
                        }else if(number < 10.0 && test_num[0] != '0'){
                            printf("\nTest mensi ako 10.00 sa musi na zaciatku zacinat 0 -> 0x.xx");
                            break;
                        }          
                        count++;
                        index = 0;
                        number = 0.0;
                        memset(test_num , 0 , sizeof(test_num));
                    }else{
                        test_num[index] = test[char_count];
                        index++;
                    }
                    if(count == 6 && test_correct != 2){
                        test_correct = 1;
                        break;
                    }
                    if (test_correct == 2){
                        test_correct = 0;
                        break;
                    }
                    
                    char_count++;
                }
            }
        }else{
            printf("\nZla dlzka vysledkov skuste to znovu zadat spravne ->");
        }if (test_correct == 0 && from_func == 0) {
            semi_column_count = 0 , char_count = 0;
            printf("\nNieco ste zadali zle. Zadajte vysledky 6tich testov v tvare xx.xx; . Za poseldnym testom nedavajte bodkociarku(;):");
            scanf(" %41[^\n]", test);
        }else if (test_correct == 0 && from_func == 1){
            printf("\nJe chyba v subore v testoch. Cislo riadku je: %d" , records+1);
            exit(1);
        }
    }
}

//checks if date is correct
void check_date(char date[11] , int from_func) {
    int date_correct = 0, check_deli = 4, append = 0, year_crrt = 0, mnt_crrt = 0, day_crrt = 0, day_cmpr_month = 0;
    char input_year[5], input_month[3], input_date[3];
    char check_31_days[7][3] = {"01","03","05","07","08","10","12"};
    char check_30_days[4][3] = {"04","06","09","11"};
    while (date_correct == 0) {
        //lenght must be same always
        if (strlen(date) == 10) {
            append = 0, year_crrt = 0, mnt_crrt = 0, day_crrt = 0, check_deli = 4;

            //get date input to strings
            for (int i = 0; i < 10; i++) {
                if (i == 0) {
                    if (date[0] == 49 || date[0] == 50) {
                        input_year[append] = date[i];
                        append++;
                    } else {
                        printf("Rok musi byt vacsi ako 999 a mensi ako 2023!\n");
                        date_correct = 2;
                    }
                } else if (i == check_deli) {
                    check_deli += 3;
                    append = 0;
                } else if (i < 4) {
                    if (date[i] > 47 && date[i] < 58) {
                        input_year[append] = date[i];
                        append++;
                    } else {
                        printf("V roku sa musia nachadzat iba cisla!\n");
                        date_correct = 2;
                    }
                } else if (i < 7) {
                    if (date[i] > 47 && date[i] < 58) {
                        input_month[append] = date[i];
                        append++;
                    } else {
                        printf("V mesiaci sa musia nachadzat iba cisla! Pokial je mesiac mensi ako 10 treba ho zadavat v tvare \"0x\"\n");
                        date_correct = 2;
                    }
                } else if (i > 7 && i < 10) {
                    if (date[i] > 47 && date[i] < 58) {
                        input_date[append] = (char) date[i];
                        append++;
                    } else {
                        printf("V roku sa musia nachadzat iba cisla! Pokial je den mensi ako 10 treba ho zadavat v tvare \"0x\"\n");
                        date_correct = 2;
                    }
                } else {
                    continue;
                }
            }

            // check if dates are correct 
            if (date_correct != 2) {
                // look at year
                int correct_year = atoi(input_year);
                if (correct_year >= 1000 && correct_year <= 2022) {
                    year_crrt = 1;
                } else {
                    printf("\nZle zadany rok. Rok musi byt vacsi ako 999 a mensi ako 2023");
                }

                // look at month 
                if (input_month[0] == 49) {
                    if (input_month[1] <= 50 && input_month[1] >= 48) {
                        mnt_crrt = 1;
                    } else {
                        printf("\nMesiac nesmie byt vacsi ako 12 pretoze mame 12 mesiacov v roku!!!\n");
                    }
                } else {
                    if (input_month[0] == 48 && input_month[1] != 48) {
                        mnt_crrt = 1;
                    } else {
                        printf("\nMesiac nesmie byt vacsi ako 12 pretoze mame 12 mesiacov v roku!!!\n");
                    }

                }

                // get how much days got specific month
                for (int a = 0; a < 7; a++) {
                    if (strcmp(input_month, check_31_days[a]) == 0) {
                        day_cmpr_month = 1;
                    }
                }
                if (day_cmpr_month == 0) {
                    for (int a = 0; a < 4; a++) {
                        if (strcmp(check_30_days[a], input_month) == 0) {
                            day_cmpr_month = 2;
                        }
                    }
                }
                // FINALLY check that day
                if (input_date[0] == 48) {
                    if (input_date[1] == 48) {
                        printf("\nNemozete zadat datum ako 00");
                        day_crrt = 0;
                    } else {
                        snprintf(date, 11, "%s/%s/%s", input_year, input_month, input_date);
                        day_crrt = 1;
                    }
                } else {
                    int current_day = atoi(input_date);
                    if ((day_cmpr_month == 1 && current_day <= 31) || (day_cmpr_month == 2 && current_day <= 30) || (day_cmpr_month == 0 && current_day <= 29)) {
                        snprintf(date, 11, "%s/%s/%s", input_year, input_month, input_date);
                        day_crrt = 1;
                    } else {
                        printf("V mesiaci je zadany nespravny pocet dni!!\n");
                    }
                }
            }
        }
        //if evrything is correct leave this function
        if (year_crrt == 1 && mnt_crrt == 1 && day_crrt == 1) {
            date_correct = 1;
        } else{
            if(from_func == 1){
                printf("\nTento subor sa neda precitat kvoli nespravnemu datumu. Chyba sa stala na riadku: %d" , records + 1);
                exit(1);
            }
            printf("\nDatum je zle zadany. Rok musi byt vacsi ako 999 a mensi ako 2023, ked je mesiac mensi ako 10 treba ho zadavat v tvare \"0x\" a to iste plati pri dnoch. Na konci nezadavajate bodkociarku(;).");
            fflush(stdin);
            gets(date);
        }
    }
}

int summary() {
    printf("\n%d records read.\n\n", records);
    for (int i = 0; i < records; i++) {
        get_gender(students[i].gender);
        printf("%s, nar. %s, %s , Kraj: %s\nVysledky testov: ", students[i].name, students[i].year, current_gender, students[i].region);
        for (int a = 0; a < 6; a++) {
            printf("%.2f", students[i].result[a]);
            if (a < 5) {
                printf(";");
            } else {
                printf("\n");
            }
        }
    }
}

int who() {
    int controll_num = 0, remember_num = records + 1 , name_found = 0;
    float average = 0.0, compare[2] = {100.0 , 0.0};
    char last_name[50];
    //get record id
    get_last_name(&remember_num , 0);

    //return record of student
    if (remember_num != records + 1) {
        get_gender(students[remember_num].gender);
        printf("%s\nnar. %s, %s\nKraj: %s\n\nVysledky testov: ", students[remember_num].name, students[remember_num].year, current_gender, students[remember_num].region);
        for (int a = 0; a < 6; a++) {
            if (students[remember_num].result[a] < compare[0]) {
                compare[0] = students[remember_num].result[a];
            } else if (students[remember_num].result[a] > compare[1]) {
                compare[1] = students[remember_num].result[a];
            }
            average += students[remember_num].result[a];

            printf("%.2f", students[remember_num].result[a]);
            if (a < 5) {
                printf(";");
            } else {
                printf("\n\nNajlepsi test: %.2f\nNajhorsi test: %.2f\nPriemerny test: %.2f\n", compare[1], compare[0], (average / 6.0));
            }
        }

    } else {
        printf("\nThis person is not in records");
    }
}

int best() {
    float best_result = 0.00;
    int number_of_test, student_id;
    for (int i = 0; i < records; i++) {
        for (int a = 0; a < 6; a++) {
            if (students[i].result[a] > best_result) {
                best_result = students[i].result[a];
                student_id = i;
                number_of_test = a;
            } else {
                continue;
            }
        }
    }
    printf("Najlepsi test: %.2f\nStudent: %s\nCislo testu: %d", best_result, students[student_id].name, number_of_test + 1);
}

int gender(){
    char gen_value;
    //getting right input
    printf("\nZvol f pre zeny a m pre muzov\n");
    scanf(" %c", &gen_value);
    check_gender(&gen_value);

    //looking for best result
    float best_result = 0.00;
    int number_of_test, student_id;
    for (int i = 0; i < records; i++) {
        if (gen_value == students[i].gender)
        {
            for (int a = 0; a < 6; a++) {
                if (students[i].result[a] > best_result) {
                    best_result = students[i].result[a];
                    student_id = i;
                    number_of_test = a;
                } else {
                    continue;
                }
            }
        }
    }
    printf("Najlepsi test: %.2f\nStudent: %s\nCislo testu: %d", best_result, students[student_id].name, number_of_test + 1);
}

int region() {
    char region_list[8][40] = {"bratislavsky","trnavsky","trenciansky","nitriansky","zilinsky","banskobystricky","presovsky","kosicky"};
    int number_of_test[8], student_id[8], current_position;
    float best_result_of_region[8] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
    for (int i = 0; i < records; i++) {
        int did_get_value = 0;
        for (int a = 0; a < 8; a++) {
            //check if region is in csv file
            if (strcmp(region_list[a], students[i].region) == 0) {
                current_position = a;
                did_get_value = 1;
                break;
            }
        }
        if (did_get_value == 0) {
            //if region doesn't fit to any student skip and dont save anything
            continue;
        }
        //compare test results with best results of region
        for (int x = 0; x < 6; x++) {
            if (students[i].result[x] > best_result_of_region[current_position]) {
                best_result_of_region[current_position] = students[i].result[x];
                number_of_test[current_position] = x;
                student_id[current_position] = i;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        //if any student isnt from region skip
        if (best_result_of_region[i] != 0.00) {
            printf("\nKraj: %s\nNajlepsi test: %.2f\nStudent: %s\nCislo test: %d\n", region_list[i], best_result_of_region[i], students[student_id[i]].name, number_of_test[i] + 1);
        }
    }
}

int year() {
    int select_year = 0;

    //get correct year
    while (1)
    {
        printf("\nZadajte rok:\n");
        scanf(" %d", &select_year);
        if (select_year > 2022) {
            printf("\nTakyto rok nieje mozne zadat, najmladsi zaznam je z roku %d" , highest_year);
        }else if (select_year < lowest_year)
        {
            printf("\nTakyto rok nieje mozne zadat, najstarsi zaznam je z roku %d" , lowest_year);
        }else if (select_year < 2023 && select_year >= lowest_year)
        {
            break;
        }
    }

    //check for best result
    float best_result = 0.00;
    int test_id, student_id;
    for (int i = 0; i < records; i++) {
        int year = atoi(students[i].year);
        if (select_year >= year) {
            continue;
        }
        for (int a = 0; a < 6; a++) {
            if (students[i].result[a] > best_result) {
                best_result = students[i].result[a];
                test_id = a;
                student_id = i;
            }
        }
    }
    if (best_result == 0.00) {
        printf("\nTakyto rok nieje mozne zadat, najmladsi zaznam je z roku %d" , highest_year);
    } else {
        printf("%s\nnar. %s\nNajlepsi test: %.2f\nCislo testu: %d", students[student_id].name, students[student_id].year, best_result, test_id + 1);
    }
}

int average() {
    int student_id;
    float best_result = 0.00, result = 0.00;
    for (int i = 0; i < records; i++) {
        for (int a = 0; a < 6; a++) {
            result += students[i].result[a];
        }
        result = result / 6.0;
        if (result > best_result) {
            best_result = result;
            student_id = i;
        }
        printf("%s - %.2f\n", students[i].name, result);
        result = 0.00;
    }
    printf("\nNajlepsie:\n%s - %.2f\n", students[student_id].name, best_result);
}

int over() {
    float limit_points;
    //get right input
    while (1)
    {
        printf("\nZadajte minimalny pocet bodov\n");
        scanf(" %f", & limit_points);
        if (limit_points > 100.00 && limit_points < 0.00) {
            printf("\nToto percento je moc velke alebo moc male");
        } else if (limit_points < 100.00 && limit_points > 0.00){
            break;
            }
    }
    
    //loop trough test and find better or equal results
    int test_id[6], count = 0;
    float test_results[6];
    for (int i = 0; i < records; i++) {
        //reset values
        for (int asd = 0; asd < 6; asd++) {
            test_id[asd] = 0;
            test_results[asd] = 0.00;
            count = 0;
        }
        //look for same or better results
        for (int a = 0; a < 6; a++) {
            if (students[i].result[a] >= limit_points) {
                count++;
                test_results[a] = students[i].result[a];
                test_id[a] = a;
            }
        //output
        }if (count == 0) {
            printf("%s - Ziadne lepsie testy ako zadana hodnota\n", students[i].name);
            continue;
        } else if (count == 1) {
            printf("%s - 1 test", students[i].name);
        } else if(count > 1 && count < 5){
            printf("%s - %d testy", students[i].name, count);
        }else{
            printf("%s - %d testov", students[i].name, count);
        }
        if (count != 0) {
            for (int z = 0; z < 6; z++) {
                if (test_results[z] != 0.00) {
                    printf(", %d (%.2f)", (test_id[z] + 1), test_results[z]);
                }
            }
        }
        printf("\n");
    }
}

int newstudent() {
    memset(controll_name , 0 , sizeof(controll_name));
    fflush(stdin);
    char date_of_birth[11], gender_input, new_region[20], test[42], prefix[150];
    int gender_correct = 0, region_correct = 0;
    printf("Zadajte meno studenta: \n");
    gets(controll_name);
    check_name(1);

    // //get date of birth and check if is correct date
    printf("\nDatum narodenia:\n");
    fflush(stdin);
    gets(date_of_birth);
    check_date(date_of_birth , 0);

    // // get gender input and check if gender input is correct
    printf("\nPohlavie (m,f): ");
    scanf("%c", & gender_input);
    check_gender( & gender_input);

    // // get region and check correctness
    printf("\nRegion:\n");
    scanf(" %s", new_region);
    check_region(new_region , 0);

    //get tests and check correctness
    printf("\nZadajte vysledky 6 testov v tvare xx.xx; . Za poseldnym testom nedavajte bodkociarku(;):\n");
    scanf(" %41[^\n]", test);
    check_test(test , 0);

    //get all strings to one
    snprintf(prefix, sizeof(prefix), "\n%s;%c;%s;%s;%s", controll_name, gender_input, date_of_birth, new_region, test);

    //import to file
    FILE * data;
    data = fopen("studenti.csv", "a");

    if (data == NULL) {
        printf("Chyba pri otvarani subora\n");
        return 0;
    }

    fputs(prefix, data);
    printf("\nVase data boli nahrane spravne!");
    fclose(data);
    get_vals();
    summary();
}

int delstudent(){
    int skip_id;
    char input[150] , test[6];
    get_last_name(&skip_id , 0);
    FILE * data;
    data = fopen("studenti.csv", "w");
    for (int i = 0; i < records; i++)
    {
        //if we are on id of selected record dont write him into file
        if (i != skip_id)
        {
            memset(input , 0 , sizeof(input));
            snprintf(input , sizeof(input) , "%s;%c;%s/%s/%s;%s" , students[i].name , students[i].gender , students[i].year , students[i].month , 
            students[i].date , students[i].region);
            fputs(input , data);
            for (int a = 0; a < 6; a++)
            {
                memset(test , 0 , sizeof(test));
                if (students[i].result[a] < 10.0){
                    fprintf(data , ";0%.2f" , students[i].result[a]);
                }else{
                    fprintf(data , ";%.2f" , students[i].result[a]);
                }
            }
            if (i != (records - 1)){
                //preventing \n when deleting last student of csv file
                if (skip_id == records-1 && i == records - 2){
                    continue;
                }else{
                    fputs("\n" , data);
                }
                
            }
        }  
    }
    fclose(data);
    printf("\nStudent s menom \"%s\" bol vymazany." , students[skip_id].name);
}

int change(){
    int student_id , test_id;
    char input[150] , test_result[5] , test[6];
    float number;
    //get specific student
    get_last_name(&student_id , 0);
    while (1)
    {
        printf("\nAk nechcete uz zmenit hodnotu dalsieho testu zadajte 0. Zadajte cislo testu od 1 po 6:\n");
        scanf(" %d" , &test_id);
        //change test's how much time you want
        if (test_id == 0){
            break;
        }else if(test_id >= 1 && test_id <= 6){
            number = 0.0;
            printf("\nZadajte vysledok testu:\n");
            scanf(" %s" , &test_result);
            number = atof(test_result);
            if (strlen(test_result) == 5){
                if (number > 0.00 && number < 100.00){
                    students[student_id].result[test_id-1] = number;
                }else{
                    printf("\nTakyto vysledok sa neda zapisat.");
                }
            }else if(strlen(test_result) == 6 && number != 100.00){
                printf("\nVysledok nemoze byt vacsi ako 100. Pri 5cifernych cislach mozete zadat iba 100.00.");
            }else{
                printf("\nZla dlzka retazca Ked zadavate vysledok mensi ako 10 zadajte prosim 0x.xx, cislo moze byt len 4-ciferne.");
            }
        }else{
            printf("\nTakyto test neexistuje.");
        }
    }
    //rewrite all data
    FILE* data;
    data = fopen("studenti.csv" , "w");
    for (int i = 0; i < records; i++)
    {
        memset(input , 0 , sizeof(input));
        snprintf(input , sizeof(input) , "%s;%c;%s/%s/%s;%s" , students[i].name , students[i].gender , students[i].year , students[i].month , students[i].date , students[i].region);
        fputs(input , data);
        for (int a = 0; a < 6; a++)
        {
            memset(test , 0 , sizeof(test));
            if (students[i].result[a] < 10.0){
                fprintf(data , ";0%.2f" , students[i].result[a]);
            }else{
                fprintf(data , ";%.2f" , students[i].result[a]);
            }
        }
        if (i != (records - 1)){
                fputs("\n" , data);
            }
    }
    fclose(data);
    get_vals();
    summary();
}

int main() {
    char action;
    get_vals();
    printf("\nvyber si akciu:\ns - sum\nw - who\nb - best\ng - gender\nr - region\ny - year\na - average\no - over\nc - change\nn - new_student\nd - delete\nx - koniec\n");
    scanf(" %c", &action);
    printf("\n");
    switch (action) {
    case 's':
        summary();
        break;
    case 'y':
        year();
        break;
    case 'o':
        over();
        break;
    case 'r':
        region();
        break;
    case 'a':
        average();
        break;
    case 'b':
        best();
        break;
    case 'g':
        gender();
        break;
    case 'w':
        who();
        break;
    case 'n':
        newstudent();
        break;
    case 'd':
        delstudent();
        break;
    case 'c':
        change();
        break;
    case 'x':
        exit(1);
    default:
        printf("\nNespravne zadana funkcia");
        break;
    }
    return main();
}