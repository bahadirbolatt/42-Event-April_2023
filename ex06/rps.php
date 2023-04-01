<?php
$options = array('rock', 'paper', 'scissors');
$computer_choice = $options[rand(0, 2)];

echo "Choose rock, paper, or scissors: ";
$user_choice = trim(fgets(STDIN, 1024), " \n");
//var_dump($user_choice);

if (!in_array($user_choice, $options))
    echo "Invalid choice!\n";

else
{
    if ($user_choice === $computer_choice)
        echo "It's a tie!\n";
    
    elseif (($user_choice === 'rock' && $computer_choice === 'scissors') ||
            ($user_choice === 'paper' && $computer_choice === 'rock') ||
            ($user_choice === 'scissors' && $computer_choice === 'paper'))
        echo "Congratulations! You won! The computer chose $computer_choice.\n";

    else
        echo "Sorry, you lost. The computer chose $computer_choice.\n";
}
?>
