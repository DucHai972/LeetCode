class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        check = 0

        while (True):
            if check > len(students):
                break
            if len(students) == 0:
                return 0
            if students[0] == sandwiches[0]:
                sandwiches.pop(0)
                students.pop(0)
                check = 0
            else:
                students.append(students[0])
                students.pop(0)
                check += 1
        
        return len(students)
    
        
