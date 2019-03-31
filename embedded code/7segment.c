#include <stdio.h>
int led_Light(char b)
{
    switch(b)
    {
        case '1':
        return 0b00000110;
        break;
        case '2':
        return 0b01011011;
        break;
        case '3':
        return 0b01001111;
        break;
        case '4':
        return 0b01100110;
        break;
        case '5':
        return 0b01101101;
        break;
        case '6':
        return 0b01111101;
        break;
        case '7':
        return 0b00000111;
        break;
        case '8':
        return 0b01111111;
        break;
        case '9':
        return 0b01101111;
        break;
        case 'A':
        return 0b01110111;
        break;
        case 'B':
        return 0b01111100;
        break;
        case 'C':
        return 0b00111001;
        break;
        case 'D':
        return 0b01011110;
        break;
        case 'E':
        return 0b01111001;
        break;
        case 'F':
        return 0b01110001;
        break;
        default:
            printf("error\n");
    }
}
int main(){
    char x;
    int a = 0;
    printf("enter your number:");
    scanf("%c", &x);
    a = led_Light(x);
    printf("%d", a);

}
