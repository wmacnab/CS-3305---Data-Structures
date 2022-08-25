

#include <stack>
#include <cctype> // Provides isdigit()
#include "exptree.h"

namespace wmacnab_10
{
    // Constructors and destructor
    exptree::exptree(const std::string& prefix_expression)
    {
        std::stack<int> nums;
        std::stack<char> ops;
        for (unsigned int i = 0; i < prefix_expression.length(); ++i)
        {
            // Case 1: number
            // Case 2: operator
            // Case 3: space
            if (prefix_expression[i] == '+' || prefix_expression[i] == '*')
            {
                ops.push(prefix_expression[i]);
            }
            else
            {
                std::string num;
                while (isdigit(prefix_expression[i]))
                {
                    num.push_back(prefix_expression[i]);
                }
                //int n = num.
                
            }
        }
    }
}