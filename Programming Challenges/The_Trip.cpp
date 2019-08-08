#include <iostream>

double studentsFinalCost(double* studentsCosts, int students) {
    double sum = 0, sum1 = 0, sum2 = 0, media = 0.0;
    for (int i = 0; i < students; i++) {
        studentsCosts[i] *= 100;
        sum += studentsCosts[i]; 
    }
    media = sum/students;
    for (int i = 0; i < students; i++) {
        sum1 += abs(studentsCosts[i] - media);
        sum2 += studentsCosts[i] - media;
    }
    return (sum1 - sum2)/200.0;
}   

int main () {
    int students;
    double* studentsCosts;
    while (1) {
        scanf("%i", &students);
        if (students == 0) break;

        studentsCosts = (double*) malloc(students*sizeof(double));
        for (int i = 0; i < students; i++) scanf("%lf", &studentsCosts[i]);

        printf("$%.2lf\n", studentsFinalCost(studentsCosts, students));
    }
    return 0;
}