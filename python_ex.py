# Python: Demonstrate types, scopes, and closures

# Class
class User:

    # Constructor
    def __init__(self, name):
        self.name = name

if __name__ == "__main__":

    # Object
    me = User("Student")

    print(f"Me: {me.name}")

    # Array
    nums = [1, 2.4, 3e3, 4/3]

    # Print an array, get length, access elements
    print(f"Nums: {nums} of length: {len(nums)} with nums[0]: {nums[0]}")

    # Array can have mixed types
    mixed_types = [1, "one", '1', me]

    print(f"Mixed types: {mixed_types} of length: {len(mixed_types)}")

    # Tuples
    tuples = (1, 2)

    print(f"Tuples: {tuples} of length: {len(tuples)}, with {tuples[0]}, {tuples[1]}")

    # Dictionary
    my_dict = {"one": 1, 4: 45}

    # Access dictionary values
    print(f'Dict entries: one - {my_dict["one"]}, 4 - {my_dict[4]}')

    def scoped_fn(a, b, c):
        print(f"Args: {a}, {b}, {c}")

        # Change scope
        a = 56
        print(f"Scoped: {a}, {b}, {c}")

        def nested_fn():
            print("Nested fn")

        nested_fn()

    scoped_fn(1, 2, 3)

    def closure_fn(c):

        # Captures variable
        def inner_fn():
            print(f"Closure captured: {c}")

        return inner_fn

    a_closure = closure_fn("value x")

    a_closure()
        
    if True:
        leaked_var = "Leaky!"

    print(f"Leaked local: {leaked_var}")
    
