import unittest

from domain.validators import ClientValidator
from exceptions.exceptions import ValidationException, ClientNotFoundException
from repository.client_repo import ClientInMemoryRepo
from service.client_service import ClientService


class TestCaseClientService(unittest.TestCase):
    def setUp(self) -> None:
        repo = ClientInMemoryRepo()
        validator = ClientValidator()
        self.__srv = ClientService(repo, validator)

    def test_add_client(self):
        added_client = self.__srv.add_client('1', 'Maya', 21)
        self.assertTrue(added_client.getNume() == 'Maya')
        self.assertTrue(added_client.getVarsta() == 21)

        self.assertEqual(len(self.__srv.get_all_clients()), 1)
        self.assertRaises(ValidationException, self.__srv.add_client, '2', 'Margo', 201)

    def test_delete_client(self):
        added_client = self.__srv.add_client('1', 'Maya', 21)
        deleted_client = self.__srv.delete_client('1')

        self.assertEqual(len(self.__srv.get_all_clients()), 0)
        self.assertTrue(deleted_client.getNume() == 'Maya')
        self.assertTrue(deleted_client.getVarsta() == 21)

        self.assertRaises(ClientNotFoundException, self.__srv.delete_client, '2')

    def test_get_all_clients(self):
        added_client1 = self.__srv.add_client('1', 'Maya', 21)
        added_client2 = self.__srv.add_client('2', 'Andre', 39)
        self.assertIsInstance(self.__srv.get_all_clients(), list)
        self.assertEqual(len(self.__srv.get_all_clients()), 2)

    def test_update_client(self):
        added_client = self.__srv.add_client('1', 'Mara',21)
        updated_client = self.__srv.update_client('1', 'Mara Ioana', 21)

        self.assertTrue(updated_client.getNume() == 'Mara Ioana')
        self.assertTrue(updated_client.getVarsta() == 21)
        self.assertRaises(ClientNotFoundException, self.__srv.update_client, 'INVALID ID', 'Anton', 87)
