// Main libs declaration
#include <cs50.h>
#include <stdio.h>

// Draw blocks prototype
void draw(int n);

// Main function
int main(void)
{
    int height = get_int("Height: ");
    draw(height);

}

// Draw blocks function
void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
