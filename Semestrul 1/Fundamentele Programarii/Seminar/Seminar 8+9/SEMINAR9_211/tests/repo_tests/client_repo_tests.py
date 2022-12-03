import unittest

from domain.entities import Client
from exceptions.exceptions import DuplicateIDException, ClientNotFoundException
from repository.client_repo import ClientInMemoryRepo, ClientFileRepo, ClientFileRepoInheritance


class TestCaseClientRepoInMemory(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = ClientInMemoryRepo()
        self.__add_predefined_clients()

    def __add_predefined_clients(self):
        client1 = Client('1', 'Alexandra', 35)
        client2 = Client('2', 'Mara', 41)
        client3 = Client('3', 'Mircea', 23)
        client4 = Client('4', 'Adrian', 53)
        client5 = Client('5', 'Rafa', 29)

        self.__repo.store(client1)
        self.__repo.store(client2)
        self.__repo.store(client3)
        self.__repo.store(client4)
        self.__repo.store(client5)

    def test_find(self):
        p = self.__repo.find('1')
        self.assertTrue(p.getNume() == 'Alexandra')
        self.assertTrue(p.getVarsta() == 35)

        p1 = self.__repo.find('765')
        self.assertIs(p1, None)

    def test_size(self):
        self.assertEqual(self.__repo.size(), 5)

        self.__repo.delete('1')
        self.__repo.delete('2')

        self.assertEqual(self.__repo.size(), 3)

        self.__repo.store(Client('7', 'Marjorie', 87))
        self.assertEqual(self.__repo.size(), 4)
        self.__repo.update('7', Client('7', 'Marge', 87))
        self.assertEqual(self.__repo.size(), 4)

    def test_get_all(self):
        crt_clients = self.__repo.get_all()
        self.assertIsInstance(crt_clients, list)

        self.assertEqual(len(crt_clients), 5)

        self.__repo.delete('1')
        self.__repo.delete('2')

        crt_clients = self.__repo.get_all()
        self.assertEqual(len(crt_clients), 3)

    def test_store(self):
        initial_size = self.__repo.size()
        client1 = Client('23', 'Cristiana', 42)
        self.__repo.store(client1)

        self.assertEqual(self.__repo.size(), initial_size + 1)
        client2 = Client('473', 'Dana', 20)
        self.__repo.store(client2)
        self.assertEqual(self.__repo.size(), initial_size + 2)
        self.assertRaises(DuplicateIDException, self.__repo.store, client2)

    def test_delete(self):
        initial_size = self.__repo.size()
        deleted_client = self.__repo.delete('4')
        self.assertTrue(deleted_client.getNume() == 'Adrian')
        self.assertTrue(self.__repo.size() == initial_size - 1)

        self.assertRaises(ClientNotFoundException, self.__repo.delete, 'wrongID')

    def test_update(self):
        client3 = Client('3', 'Kim', 77)

        modified_client = self.__repo.update('3', client3)
        self.assertEqual(modified_client.getNume(), 'Kim')
        self.assertEqual(modified_client.getVarsta(), 77)
        self.assertRaises(ClientNotFoundException, self.__repo.update, '243545', Client(3, 'Alfred', 67))


class TestCaseClientRepoFile(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = ClientFileRepoInheritance('test_clients_repo.txt')
        self.__add_predefined_clients()

    def __add_predefined_clients(self):
        client1 = Client('1', 'Alexandra', 35)
        client2 = Client('2', 'Mara', 41)
        client3 = Client('3', 'Mircea', 23)
        client4 = Client('4', 'Adrian', 53)
        client5 = Client('5', 'Rafa', 29)

        self.__repo.store(client1)
        self.__repo.store(client2)
        self.__repo.store(client3)
        self.__repo.store(client4)
        self.__repo.store(client5)

    def test_find(self):
        p = self.__repo.find('1')
        self.assertEqual(p.getNume(),'Alexandra')
        self.assertEqual(p.getVarsta(), 35)

        p1 = self.__repo.find('765')
        self.assertIs(p1, None)

    def test_size(self):
        self.assertEqual(self.__repo.size(), 5)

        self.__repo.delete('1')
        self.__repo.delete('2')

        self.assertEqual(self.__repo.size(), 3)

        self.__repo.store(Client('7', 'Marjorie', 87))
        self.assertEqual(self.__repo.size(), 4)
        self.__repo.update('7', Client('7', 'Marge', 87))
        self.assertEqual(self.__repo.size(), 4)

    def test_get_all(self):
        crt_clients = self.__repo.get_all()
        self.assertIsInstance(crt_clients, list)

        self.assertEqual(len(crt_clients), 5)

        self.__repo.delete('1')
        self.__repo.delete('2')

        crt_clients = self.__repo.get_all()
        self.assertEqual(len(crt_clients), 3)

    def test_store(self):
        initial_size = self.__repo.size()
        client1 = Client('23', 'Cristiana', 42)
        self.__repo.store(client1)

        self.assertEqual(self.__repo.size(), initial_size + 1)
        client2 = Client('473', 'Dana', 20)
        self.__repo.store(client2)
        self.assertEqual(self.__repo.size(), initial_size + 2)
        self.assertRaises(DuplicateIDException, self.__repo.store, client2)

    def test_delete(self):
        initial_size = self.__repo.size()
        deleted_client = self.__repo.delete('4')
        self.assertTrue(deleted_client.getNume() == 'Adrian')
        self.assertTrue(self.__repo.size() == initial_size - 1)

        self.assertRaises(ClientNotFoundException, self.__repo.delete, 'wrongID')

    def test_update(self):
        client3 = Client('3', 'Kim', 77)

        modified_client = self.__repo.update('3', client3)
        self.assertEqual(modified_client.getNume(), 'Kim')
        self.assertEqual(modified_client.getVarsta(), 77)
        self.assertRaises(ClientNotFoundException, self.__repo.update, '243545', Client(3, 'Alfred', 67))

    def tearDown(self) -> None:
        self.__repo.delete_all()
