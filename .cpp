void displayOldestStudent(struct student s1[], int n)
{
    int oldest = s1[0].age;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (oldest > s1[i].age)
        {
            oldest = s1[i].age;
            index = 1;
        }
    }

    printf("\nStudent with highest age:\n");
    printf("Student id:-");
    printf("%d",s1[index].studentID);
    printf("Student name:-");
    printf("%d",s1[index].name);
    printf("Student age:-");
    printf("%d",s1[index].age);

}