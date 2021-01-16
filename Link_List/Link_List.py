class Node:
    def __init__(self, item):
        self.prior = None
        self.item = item
        self.next = None


def create_linklist_head(list): #头插法
    head = Node(list[0])
    for element in list[1:]:
        node = Node(element)
        node.next = head
        head.prior = node
        head = node
    return head


def create_linklist_tail(list): #尾插法
    head = Node(list[0])
    tail = head
    for element in list[1:]:
        node = Node(element)
        tail.next = node
        node.prior = tail
        tail = node
    return head


#遍历列表
def print_linklist(lk):
    while lk:
        if lk.next:
            print(lk.item, end='<->')
        else:
            print(lk.item)
        lk = lk.next


def insert_linklist(cur_node, node):
    node.next = cur_node
    cur_node.next = node


#def delete_linklist(cur_node, node)


lk1 = create_linklist_head([1, 2, 3, 4, 5])
lk2 = create_linklist_tail([1, 2, 3, 4, 5])

print(lk2.next.prior.item)
print_linklist(lk1)
print_linklist(lk2)


class LinkList:
    class Node:
        def __init__(self, item = None):
            self.item = item
            self.next = None

    class LinkListIterator:
        def __init__(self, node):
            self.node = node

        def __next__(self):
            if self.node:
                cur_node = self.node
                self.node = cur_node.next
                return cur_node.item
            else:
                raise StopIteration

        def __iter__(self):
            return self

    def __init__(self, iterable = None):
        self.head = None
        self.tail = None
        if iterable:
            self.extend(iterable)

    def append(self, obj):
        s = LinkList.Node(obj)
        if not self.head:
            self.head = s
            self.tail = s
        else:
            self.tail.next = s
            self.tail = s

    def extend(self, iterable):
        for obj in iterable:
            self.append(obj)

    def find(self, obj):
        for n in self:
            if n == obj:
                return True
        else:
            return False

    def __iter__(self):
        return self.LinkListIterator(self.head)

    def __repr__(self):
        return "<<"+", ".join(map(str, self))+ ">>"

