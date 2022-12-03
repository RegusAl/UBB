import unittest

from domain.validators import ShowValidator
from exceptions.exceptions import ValidationException, ShowNotFoundException
from repository.show_repo import ShowInMemoryRepo
from service.show_service import ShowService


class TestCaseShowService(unittest.TestCase):
    def setUp(self) -> None:
        repo = ShowInMemoryRepo()
        validator = ShowValidator()
        self.__srv = ShowService(repo, validator)

    def test_add_show(self):

        added_show = self.__srv.add_show('1', 'See', 2019, 12)
        self.assertTrue(added_show.getTitle() == 'See')
        self.assertTrue(added_show.getEpisoade() == 12)

        self.assertEqual(len(self.__srv.get_all_shows()), 1)
        self.assertRaises(ValidationException, self.__srv.add_show, '2', 'See', 1200, 12)

    def test_delete_show(self):

        self.__srv.add_show('1', 'See', 2019, 12)
        deleted_show = self.__srv.delete_show('1')

        self.assertEqual(len(self.__srv.get_all_shows()), 0)
        self.assertEqual(deleted_show.getTitle(), 'See')
        self.assertEqual(deleted_show.getAnAparitie(), 2019)
        self.assertEqual(deleted_show.getEpisoade(), 12)
        self.assertRaises(ShowNotFoundException, self.__srv.delete_show, '2')

    def test_get_all_shows(self):

        self.__srv.add_show('1', 'See', 2019, 16)
        self.__srv.add_show('2', 'Modern Family', 2009, 250)
        self.assertIsInstance(self.__srv.get_all_shows(), list)
        self.assertEqual(len(self.__srv.get_all_shows()), 2)

    def test_update_show(self):

        self.__srv.add_show('1', 'See', 2019, 12)
        updated_show = self.__srv.update_show('1', 'See (TV SHOW)', 2019, 16)

        self.assertTrue(updated_show.getTitle() == 'See (TV SHOW)')
        self.assertTrue(updated_show.getAnAparitie() == 2019)
        self.assertTrue(updated_show.getEpisoade() == 16)
        self.assertRaises(ShowNotFoundException,self.__srv.update_show,'INVALID ID', 'See', 2019, 16)

