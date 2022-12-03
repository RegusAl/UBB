import unittest

from domain.entities import Serial
from exceptions.exceptions import DuplicateIDException, ShowNotFoundException
from repository.show_repo import ShowInMemoryRepo, ShowFileRepo, ShowRepoFileInheritance


class TestCaseSerialRepoInMemory(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = ShowInMemoryRepo()

        serial1 = Serial('C1001', 'Superstore', 2019, 98)
        serial2 = Serial('F1001', 'Arrow', 2012, 170)
        serial3 = Serial('C1002', 'Modern Family', 2009, 250)
        serial4 = Serial('D1001', 'Squid Game', 2021, 9)
        serial5 = Serial('F1002', 'See', 2019, 16)
        serial6 = Serial('D1854', 'Grey\'s Anatomy', 2005, 384)
        serial7 = Serial('F2638', 'The Magicians', 2015, 65)
        serial8 = Serial('D1211', 'Atypical', 2017, 38)
        serial9 = Serial('D1372', 'ER', 1994, 331)
        serial10 = Serial('SF1643', 'The X-Files', 1993, 218)

        self.__repo.store(serial1)
        self.__repo.store(serial2)
        self.__repo.store(serial3)
        self.__repo.store(serial4)
        self.__repo.store(serial5)
        self.__repo.store(serial6)
        self.__repo.store(serial7)
        self.__repo.store(serial8)
        self.__repo.store(serial9)
        self.__repo.store(serial10)

    def test_find(self):
        p = self.__repo.find('SF1643')
        self.assertTrue(p.getTitle() == 'The X-Files')
        self.assertTrue(p.getAnAparitie() == 1993)
        self.assertEqual(p.getEpisoade(), 218)

        p1 = self.__repo.find('SF1645')
        self.assertIs(p1, None)

    def test_size(self):
        self.assertEqual(self.__repo.size(), 10)

        self.__repo.delete('C1001')
        self.__repo.delete('F2638')

        self.assertEqual(self.__repo.size(), 8)

        self.__repo.store(Serial('HD2384', 'The Crown', 2016, 41))
        self.assertEqual(self.__repo.size(), 9)
        self.__repo.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))
        self.assertEqual(self.__repo.size(), 9)

    def test_get_all(self):
        crt_shows = self.__repo.get_all()
        self.assertIsInstance(crt_shows, list)

        self.assertEqual(len(crt_shows), 10)

        self.__repo.delete('C1001')
        self.__repo.delete('F2638')

        crt_shows = self.__repo.get_all()
        self.assertEqual(len(crt_shows), 8)

        self.__repo.store(Serial('HD2384', 'The Crown', 2016, 41))
        self.assertTrue(self.__repo.size() == 9)

        self.__repo.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))

        self.assertTrue(self.__repo.size() == 9)

    def test_store(self):
        initial_size = self.__repo.size()
        show1 = Serial('23', 'See', 2019, 12)
        self.__repo.store(show1)

        self.assertEqual(self.__repo.size(), initial_size + 1)
        show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
        self.__repo.store(show2)
        self.assertEqual(self.__repo.size(), initial_size + 2)
        self.assertRaises(DuplicateIDException, self.__repo.store, show2)

    def test_delete(self):
        self.__repo = ShowInMemoryRepo()
        show1 = Serial('23', 'See', 2019, 12)
        self.__repo.store(show1)
        show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
        self.__repo.store(show2)

        deleted_show = self.__repo.delete('234')
        self.assertTrue(deleted_show.getTitle() == 'Kim\'s Convenience')
        self.assertTrue(self.__repo.size() == 1)

        show_left = self.__repo.find('23')
        self.assertEqual(show_left.getTitle(), 'See')
        self.assertRaises(ShowNotFoundException, self.__repo.delete, 'wrongID')

    def test_update(self):
        self.__repo = ShowInMemoryRepo()
        show1 = Serial('23', 'See', 2019, 12)
        self.__repo.store(show1)
        show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
        self.__repo.store(show2)
        show3 = Serial('234', 'Kim', 2016, 78)

        modified_show = self.__repo.update('234', show3)
        self.assertEqual(modified_show.getTitle(), 'Kim')
        self.assertEqual(modified_show.getAnAparitie(), 2016)
        self.assertEqual(modified_show.getEpisoade(), 78)
        self.assertRaises(ShowNotFoundException, self.__repo.update, '243545', Serial('234', 'Kim', 2016, 78))




class TestCaseSerialRepoFile(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = ShowRepoFileInheritance('test_shows_repo.txt')
        self.__repo.delete_all()
        self.__populate_list()

    def __populate_list(self):
        serial1 = Serial('C1001', 'Superstore', 2019, 98)
        serial2 = Serial('F1001', 'Arrow', 2012, 170)
        serial3 = Serial('C1002', 'Modern Family', 2009, 250)
        serial4 = Serial('D1001', 'Squid Game', 2021, 9)
        serial5 = Serial('F1002', 'See', 2019, 16)
        serial6 = Serial('D1854', 'Grey\'s Anatomy', 2005, 384)
        serial7 = Serial('F2638', 'The Magicians', 2015, 65)
        serial8 = Serial('D1211', 'Atypical', 2017, 38)
        serial9 = Serial('D1372', 'ER', 1994, 331)
        serial10 = Serial('SF1643', 'The X-Files', 1993, 218)

        self.__repo.store(serial1)
        self.__repo.store(serial2)
        self.__repo.store(serial3)
        self.__repo.store(serial4)
        self.__repo.store(serial5)
        self.__repo.store(serial6)
        self.__repo.store(serial7)
        self.__repo.store(serial8)
        self.__repo.store(serial9)
        self.__repo.store(serial10)

    def test_find(self):
        p = self.__repo.find('SF1643')
        self.assertTrue(p.getTitle() == 'The X-Files')
        self.assertTrue(p.getAnAparitie() == 1993)
        self.assertEqual(p.getEpisoade(), 218)

        p1 = self.__repo.find('SF1645')
        self.assertIs(p1, None)

    def test_size(self):
        initial_size = self.__repo.size()
        self.__repo.delete('C1001')
        self.__repo.delete('F2638')

        self.assertEqual(self.__repo.size(), initial_size - 2)

        self.__repo.store(Serial('HD2384', 'The Crown', 2016, 41))
        self.assertEqual(self.__repo.size(), initial_size - 1)
        self.__repo.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))
        self.assertEqual(self.__repo.size(), initial_size - 1)

    def test_get_all(self):
        initial_size = self.__repo.size()
        crt_shows = self.__repo.get_all()
        self.assertIsInstance(crt_shows, list)

        self.assertEqual(len(crt_shows), initial_size)

        self.__repo.delete('C1001')
        self.__repo.delete('F2638')

        crt_shows = self.__repo.get_all()
        self.assertEqual(len(crt_shows), initial_size - 2)

        self.__repo.store(Serial('HD2384', 'The Crown', 2016, 41))
        self.assertTrue(self.__repo.size() == initial_size - 1)

        self.__repo.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))

        self.assertTrue(self.__repo.size() == initial_size - 1)

    def test_store(self):
        initial_size = self.__repo.size()
        show1 = Serial('23', 'See', 2019, 12)
        self.__repo.store(show1)

        self.assertEqual(self.__repo.size(), initial_size + 1)
        show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
        self.__repo.store(show2)
        self.assertEqual(self.__repo.size(), initial_size + 2)
        self.assertRaises(DuplicateIDException, self.__repo.store, show2)

    def test_delete(self):
        initial_size = self.__repo.size()
        show1 = Serial('23', 'See', 2019, 12)
        self.__repo.store(show1)
        show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
        self.__repo.store(show2)

        deleted_show = self.__repo.delete('234')
        self.assertTrue(deleted_show.getTitle() == 'Kim\'s Convenience')
        self.assertTrue(self.__repo.size() == initial_size + 1)

        show_left = self.__repo.find('23')
        self.assertEqual(show_left.getTitle(), 'See')
        self.assertRaises(ShowNotFoundException, self.__repo.delete, 'wrongID')

    def test_update(self):
        show1 = Serial('23', 'See', 2019, 12)
        self.__repo.store(show1)
        show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
        self.__repo.store(show2)
        show3 = Serial('234', 'Kim', 2016, 78)

        modified_show = self.__repo.update('234', show3)
        self.assertEqual(modified_show.getTitle(), 'Kim')
        self.assertEqual(modified_show.getAnAparitie(), 2016)
        self.assertEqual(modified_show.getEpisoade(), 78)
        self.assertRaises(ShowNotFoundException, self.__repo.update, '243545', Serial('234', 'Kim', 2016, 78))

    def tearDown(self) -> None:
        self.__repo.delete_all()
