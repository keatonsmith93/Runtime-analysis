# Runtime-analysis
Runtime and memory analysis for different data structures.
What was the problem you were solving in the projects for this course?
The core problem was designing and implementing a command-line advising assistance tool for the Computer Science department. The tool needed to read course data from a file, store it efficiently, and allow users (academic advisors) to view a sorted list of courses and retrieve detailed information about individual courses and their prerequisites. The challenge was to create a system that was both functional and intuitive for non-technical users.

 How did you approach the problem? Why are data structures important to understand?
I approached the problem by first analyzing the structure of the course data and identifying the operations the system needed to support—such as fast lookup, sorting, and relational queries (e.g., prerequisites). 
I chose a map data structure in C++ to store course objects keyed by course number. This allowed for:
- Efficient retrieval of course details
- Automatic sorting by course number
- Clear organization of course relationships
Understanding data structures was essential because they directly impact performance, scalability, and code clarity. The right structure simplifies logic and reduces the need for complex algorithms.

How did you overcome any roadblocks during the activities or project?
One challenge was parsing the course data file, especially handling variable-length prerequisite lists. I overcame this by using stringstream to tokenize each line and dynamically build the prerequisites vector. Another roadblock was ensuring that course lookups were robust—even when a prerequisite course wasn’t listed in the file. I added error handling to gracefully notify the user when a course or prerequisite was missing.
I also iterated on the menu design to make it more user-friendly, ensuring that advisors could navigate the system without needing technical expertise.

 How has your work on this project expanded your approach to designing software and developing programs?
This project reinforced the importance of modular design and user-centered thinking. I broke the program into clear functions—loading data, printing lists, and showing course details—which made the code easier to test and maintain. I also focused on designing for the end user, anticipating how advisors would interact with the tool and what kind of feedback or error messages would be most helpful.
It also deepened my appreciation for data-driven design, where the structure of the input data informs the architecture of the program.

 How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
I’ve become more intentional about:
- Naming conventions that reflect purpose and improve readability
- Inline comments that explain logic without cluttering the code
- Error handling that guides users rather than confusing them
- Separation of concerns, keeping I/O, logic, and data management distinct
I also built the program with adaptability in mind—if the course format changes or new features are needed (like flowchart visualization or semester planning), the current structure can be extended without major rewrites.
