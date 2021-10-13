class Student:
    def __init__(self, birth, stu_id):
      self._birth = birth
      self._age = 2020 - self.birth
      self._stu_id = stu_id

    def get_birth(self):
        return self._birth
    def set_birth(self, birth):
        self._birth = birth
    def del_birth(self):
        print("call del_birth")
        del self._birth

    def get_age(self):
        return self._age

    birth = property(get_birth, set_birth, del_birth, "birth property")
    age = property(get_age)


    @property
    def stu_id(self):
        return self._stu_id

    @stu_id.setter
    def stu_id(self, new_id):
        self._stu_id = new_id

tony = Student(2000, "s001")
import pdb
pdb.set_trace()
print("birth of tony is {}".format(tony.birth))
tony.birth = 1995
print("birth of tony is {}".format(tony.birth))
print("age of tony is {}".format(tony.age))
del tony.birth

print("stu_id of tony is {}".format(tony.stu_id))
tony.stu_id = "c001"
print("stu_id of tony is {}".format(tony.stu_id))
