///
    /* Task. Your friend is making a text editor for programmers. He is currently working on a feature that will find errors in the usage of different types of brackets. Code can contain any brackets from the set []{}(), where the opening brackets are [,{, and ( and the closing brackets corresponding to them are ],}, and ). For convenience, the text editor should not only inform the user that there is an error in the usage of brackets, but also point to the exact place in the code with the problematic bracket. First priority is to find the first unmatched closing bracket which either doesn’t have an opening bracket before it, like ] in ](), or closes the wrong opening bracket, like } in ()[}. If there are no such mistakes, then it should find the first unmatched opening bracket without the corresponding closing bracket after it, like ( in {}([]. If there are no mistakes, text editor should inform the user that the usage of brackets is correct. Apart from the brackets, code can contain big and small latin letters, digits and punctuation marks. More formally, all brackets in the code should be divided into pairs of matching brackets, such that in each pair the opening bracket goes before the closing bracket, and for any two pairs of brackets either one of them is nested inside another one as in (foo[bar]) or they are separate as in f(a,b)-g[c]. The bracket [ corresponds to the bracket ], { corresponds to }, and ( corresponds to ). 
Input Format. Input contains one string S which consists of big and small latin letters, digits, punctuation marks and brackets from the set []{}(). Constraints. The length of S is at least 1 and at most 105. Output Format. Ifthecodein S usesbracketscorrectly,output“Success"(withoutthequotes).Otherwise, output the 1-based index of the first unmatched closing bracket, and if there are no unmatched closing brackets, output the 1-based index of the first unmatched opening bracket. 	*/
///
#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    int i=0;
    getline(std::cin, text);

    std::stack <Bracket> s;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket b(next,position);

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            s.push(b);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(s.empty()){
				Bracket s1(next,position+1);
                s.push(s1);
				break;
			}
            else{
            Bracket top = s.top();
            
            // Process closing bracket, write your code here
            if(!top.Matchc(next))
                {
                    i = position + 1;
                    break;
                }
				s.pop();
				}
        }
    }

    // Printing answer, write your code here
    if(s.empty())
        std::cout<<"Success";
    else if(s.top().type=='}' || s.top().type==']' || s.top().type==')')
         std::cout<<s.top().position;
    else 
    {
        if(i!=0)
            std::cout<<i;
        else{
            while(!s.empty())
            {
                i=s.top().position+1;
                s.pop();
            }
            std::cout<<i;
        }
    }
    
    return 0;
}





