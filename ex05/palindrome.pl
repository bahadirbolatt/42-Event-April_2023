print "Enter a string: ";

my $input = <STDIN>;       # my is using for assign a variable
chomp $input;              # chop off newline character

my $reversed = reverse $input; 

if ($input eq $reversed)    # if equal
{
    print "The string is a palindrome!\n";
} 
else
{
    print "The string is not a palindrome.\n";
}
