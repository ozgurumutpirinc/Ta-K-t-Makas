#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

char hamle_goster()
{
    int num = rand() % 3 + 1;

    switch(num)
    {
        case 1: return 'T';
        break;
        case 2: return 'K';
        break;
        case 3: return 'M';
        break;
    }
}

char player_move()
{
    char oyuncu_hamle;
    puts("T / K / M");
    puts("Hamlenizi giriniz:");

    //oyuncu_hamle = getchar();
    scanf(" %c", &oyuncu_hamle);
    oyuncu_hamle = toupper(oyuncu_hamle);

    if(oyuncu_hamle != 'T' && oyuncu_hamle != 'K' && oyuncu_hamle != 'M' && oyuncu_hamle != 'Q')
    {
        puts("Lutfen gecerli bir hamle giriniz!");
        sleep(1);
        system("cls");
        return player_move();
    }
    else
    {
        return oyuncu_hamle;
    }

}


int game_screen()
{
    char computer_move = hamle_goster();
    char human_move = player_move();

    char human_move_[10];
    char computer_move_[10];
    int flag; //1 -> berabere 2 -> oyuncu 3 -> bilgisayar

    if(computer_move == 'T')
        strcpy(computer_move_, "Tas");
    else if(computer_move == 'K')
        strcpy(computer_move_, "Kagit");
    else
        strcpy(computer_move_, "Makas");
    if(human_move == 'T')
        strcpy(human_move_, "Tas");
    else if(human_move == 'K')
        strcpy(human_move_, "Kagit");
    else
        strcpy(human_move_, "Makas");





    printf("Bilgisayar hamle:  %s\n", computer_move_);
    printf("Oyuncu hamle:\t%s\n", human_move_);

    if(human_move == 'T')
    {
        if(computer_move == 'T')
        {
            printf("Berabere!\n");
            flag = 1;
            return flag;
        }
        else if(computer_move == 'M')
        {
            printf("Oyuncu kazandi!\n");
            flag = 2;
            return flag;
        }
        else
        {
            printf("Bilgisayar kazandi!\n");
            flag = 3;
            return flag;
        }
    }
    else if(human_move == 'K')
    {
        if(computer_move == 'T')
        {
            printf("Oyuncu kazandi!\n");
            flag = 2;
            return flag;
        }
        else if(computer_move == 'M')
        {
            printf("Bilgisayar kazandi!\n");
            flag = 3;
            return flag;
        }
        else
        {
              printf("Berabere!\n");
              flag = 1;
              return flag;
        }
    }
    else if(human_move == 'M')
    {
        if(computer_move == 'T')
        {
            printf("Bilgisayar kazandi!\n");
            flag = 3;
            return flag;
        }
        else if(computer_move == 'M')
        {
            printf("Berabere!\n");
            flag = 1;
            return flag;
        }
        else
        {
              printf("Oyuncu kazandi!\n");
              flag = 2;
              return flag;
        }
    }
    else if(human_move == 'Q')
    {
        flag = 4;
        return flag;
    }

}

int main()
{
   srand(time(NULL));

    int player_score = 0;
    int computer_score = 0;
    int result;
    int round_num = 1;
    while(1)
    {
        printf("Round %d\n\n", round_num);

        result = game_screen();
        if(result == 2)
        {
            player_score++;
        }
        else if(result == 3)
        {
            computer_score++;
        }
        else if(result == 4)
            break;

        printf("Blgisayar %d :", computer_score);
        printf(" %d Oyuncu\n", player_score);
        puts("");

        puts("Cikmak icin q veya Q'ya basiniz:");

        sleep(2);
        system("cls");
        round_num++;
    }


    printf("Blgisayar %d :", computer_score);
    printf(" %d Oyuncu\n", player_score);

    puts("");
    if(player_score > computer_score)
        printf("Tebrikler!");
    else if(player_score < computer_score)
        printf("Bilgisayar kazandi!");
    else
        printf("Berabere");


    return 0;
}
