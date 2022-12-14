import unittest
from domeniu.atelier import Atelier


class TestDomeniu(unittest.TestCase):

    def setUp(self) -> None:
        pass

    def test_create(self):
        atelier1 = Atelier("Santa's hub", "Finlanda", "cadouri", 300)
        self.assertEqual (atelier1.get_nume(), "Santa's hub")
        self.assertEqual (atelier1.get_locatie(), "Finlanda")
        self.assertEqual (atelier1.get_produs(), "cadouri")
        self.assertEqual (atelier1.get_numar_spiridusi(), 300)