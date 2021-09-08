#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int midterm;
    int final;
} Score;

void printScore(Score *p)
{
    printf("중간고사 성적은 %d\n", p->midterm);
    printf("학기말고사 성적은 %d\n", p->final);
}

Score *biggerScore(Score *p1, Score *p2)
{
    Score *temp;
    temp = (Score *)malloc(sizeof(Score));

    if (p1->midterm > p2->midterm)
        temp->midterm = p1->midterm;
    else
        temp->midterm = p2->midterm;

    if (p1->final > p2->final)
        temp->final = p1->final;
    else
        temp->final = p2->final;

    return temp;
}

Score *totalScore(Score *p1, Score *p2)
{
    Score *temp;
    temp = (Score *)malloc(sizeof(Score));

    temp->midterm = p1->midterm + p2->midterm;
    temp->final = p1->final + p2->final;

    return temp;
}

Score *createScore(int m, int f)
{
    Score *temp;
    temp = (Score *)malloc(sizeof(Score));

    temp->midterm = m;
    temp->final = f;

    return temp;
}

int main(void)
{
    Score s1, s2;
    Score *p3;

    s1.midterm = 50;
    s1.final = 100;

    s2.midterm = 70;
    s2.final = 70;

    printScore(&s1);
    printScore(&s2);

    printf("--------------------------\n");
    printf("둘 중 성적이 좋은 점수:\n");
    printScore(biggerScore(&s1, &s2));

    printf("--------------------------\n");
    printf("두 성적의 총 합:\n");
    printScore(totalScore(&s1, &s2));

    printf("--------------------------\n");
    p3 = createScore(100, 100);
    printScore(p3);
}