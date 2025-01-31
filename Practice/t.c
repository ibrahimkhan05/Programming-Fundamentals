do
{
    printf("Player %d: Enter a coordinate (e.g. B4 )");
    scanf(" %c%d", &selected_column_1, selected_row_1);
    mapped_column_1 = columnMapper(selected_column_1);
    if ((selected_row_1 >= 1 && selected_row_1 <= 5) && (mapped_column_1 >= 0 && mapped_column_1 <= 5))
    {
        first_card = board_contents[selected_row_1][mapped_column_1];
        revealedBoard(hash_array, second_card, selected_row_1, mapped_column_1);
        turn++;
        else if ((selected_row_1 < 1 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5))
        {
            if ((selected_row_1 < 1 || selected_row_1 > 5))
            {
                printf("You entered wrong row from board");
            }
            else if ((mapped_column_1 < 0 || mapped_column_1 > 5))
            {
                printf("You entered wrong row from board");
            }
        }
    }
    while ((selected_row_1 < 1 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5));
}
