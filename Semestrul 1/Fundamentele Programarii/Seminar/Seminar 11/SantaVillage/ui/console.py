from colorama import Fore, Style

from service.workshop_controller import WorkshopController


class Console:
    def __init__(self, ctrl: WorkshopController):
        self.__ctrl = ctrl

    def __print_menu(self):
        print("1. See all workshops")
        print("2. Search workshop with type & number of elves")
        print("3. Help Mrs. Claus organize: evaluate workshop")
        print("4. Exit")

    def __print_workshops(self, workshops):
        for workshop in workshops:
            print(workshop)

    def __get_all_with_type_and_elves_ui(self):
        product_type = input("Product type: ")
        try:
            number_of_elves = int(input("Number of elves:"))
            requested_workshops = self.__ctrl.get_all_with_type_and_elves(product_type, number_of_elves)
            self.__print_workshops(requested_workshops)
        except ValueError:
            print("Number of elves should be a number.")
        except Exception as e:
            print(Fore.RED + str(e), Style.RESET_ALL)

    def __evaluate_workshop(self):
        workshop_name = input("Workshop name:")
        try:
            number_of_days = int(input("Number of days:"))
            evaluator = self.__ctrl.evaluate_workshop(workshop_name, number_of_days)
            print(evaluator)
        except ValueError:
            print("Number of days should be a number.")
        except Exception as e:
            print(Fore.RED + str(e), Style.RESET_ALL)

    def run(self):
        while True:
            self.__print_menu()
            option = input("Option:")
            if option == '1':
                self.__print_workshops(self.__ctrl.get_all())
            elif option == '2':
                self.__get_all_with_type_and_elves_ui()
            elif option == '3':
                self.__evaluate_workshop()
            elif option == '4':
                break
            else:
                print("No such option in the menu.")
