#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[101] = "";
    int i, length;

    scanf("%s", &word);

    length = strlen(word);
    i = length - 1;

    for(i; i >= 0; i--)
    {
        switch(word[i])
        {
            case '=': 
                i--;
                switch(word[i])
                {
                    case 'c':
                        length--;
                        break;
                    case 's':
                        length--;
                        break;
                    case 'z':
                        length--;
                        i--;
                        switch(word[i])
                        {
                            case 'd':
                                length--;
                                break;
                            default:
                                i++;
                                break;
                        }
                    default:
                        i++;
                }
                break;
            case '-':
                i--;
                switch(word[i])
                {
                    case 'c':
                        length--;
                        break;
                    case 'd':
                        length--;
                        break;
                    default:
                        i++;
                }
            case 'j':
                i--;
                switch (word[i])
                {
                case 'l':
                    length--;
                    break;
                case 'n':
                    length--;
                    break;
                default:
                    i++;
                    break;
                }
            default:
                break;
        }
    }
    printf("%d", length);
}