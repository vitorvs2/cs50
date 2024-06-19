// Main libs declaration
#include <cs50.h>
#include <stdio.h>

// Draw blocks prototype
void draw(int n);

// Main function
int main(void)
{
    // get height from user
    int height = get_int("Height: ");

    // call draw function with the users height
    draw(height);

}

// Draw blocks function that calls itself in recursion
void draw(int n)
{
    // if nothing to draw, exit
    if (n <= 0)
    {
        return;
    }

    // print pyramid of height n - 1 calling itself for this
    draw(n-1);

    // print one more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
