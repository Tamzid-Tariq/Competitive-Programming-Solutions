# Contributing to CSES Solutions

## Solution Guidelines

When adding new solutions to this repository, please follow these guidelines:

### File Naming Convention
- Use lowercase letters and underscores
- Base the name on the problem title
- Example: `weird_algorithm.cpp`, `missing_number.py`

### Code Structure
```cpp
/*
Problem: [Exact Problem Name from CSES]
Link: https://cses.fi/problemset/task/[problem_id]
Author: Tamzid Tariq
Approach: [Brief explanation of your approach]
Time Complexity: O(...)
Space Complexity: O(...)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Your solution code here
    // Add comments for complex logic
    
    return 0;
}
```

### Code Quality Standards
1. **Clean and readable code**
2. **Proper variable naming**
3. **Comments for complex algorithms**
4. **Efficient solutions** (aim for optimal time complexity)
5. **Handle edge cases**

### Directory Structure
Place solutions in the appropriate category folder:
- `Introductory_Problems/`
- `Sorting_and_Searching/`
- `Dynamic_Programming/`
- `Graph_Algorithms/`
- `Range_Queries/`
- `Tree_Algorithms/`
- `Mathematics/`
- `String_Algorithms/`
- `Geometry/`
- `Advanced_Techniques/`

### Languages
- **Primary**: C++ (preferred for competitive programming)
- **Alternative**: Python (for specific cases or alternative implementations)

### Commit Message Format
```
Add solution: [Problem Name] ([Category])

- Time Complexity: O(...)
- Space Complexity: O(...)
- Brief description of approach
```

---

Happy coding! 🚀
