class Tree:
    def __init__(self):
        self.branch = "branch1"
        self.branchs = {"branch1": 1, "branch2": 2}
    def root(self):
        print("Tree root")
    def leaf(self):
        print("Tree leaf")
    def __getattr__(self, name):
        if name not in self.__dict__:
            if name in self.branchs.keys():
                return self.branchs[name]
            self.__dict__[name] = name
        return self.__dict__[name]

class FakeTree:
    def __init__(self):
        self.tree = Tree()

    def root(self):
        print("FakeTree root")

    def __getattr__(self, name):
        return getattr(self.tree, name)

tree = FakeTree()
print(tree.branch)
print(tree.branch1)
tree.root()
tree.leaf()
