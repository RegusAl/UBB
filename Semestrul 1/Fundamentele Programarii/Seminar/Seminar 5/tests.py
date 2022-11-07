from domain.show import test_create_show, test_validate_show, test_is_same_show
from domain.show_manager import test_add_show_to_manager, test_undo, test_exists_show, test_no_shows, \
    test_delete_from_manager, test_remove_show_from_list
from utils.list_operations import test_add_to_list, test_copy_list

test_validate_show()
test_create_show()
test_is_same_show()
test_exists_show()
test_undo()
test_delete_from_manager()
test_add_show_to_manager()
test_no_shows()
test_remove_show_from_list()
test_copy_list()
test_add_to_list()
