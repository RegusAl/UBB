import unittest

from domain.entities import Workshop
from domain.workshop_evaluation import WorkshopEvaluation


class TestDomain(unittest.TestCase):
    def setUp(self) -> None:
        pass

    def test_workshop(self):
        workshop1 = Workshop("Reindeer Inn", "Santa Claus Village, Glittering Road 12, North Pole", 'None', 0)

        self.assertEqual(workshop1.get_name(), "Reindeer Inn")
        self.assertEqual(workshop1.get_location(), "Santa Claus Village, Glittering Road 12, North Pole")
        self.assertEqual(workshop1.get_product_type(), "None")
        self.assertEqual(workshop1.get_number_of_elves(), 0)

        workshop2 = Workshop("Hot Chocolate Stand", "Santa Claus Village, Main Road 12, North Pole", 'hot chocolate', 1)

        self.assertEqual(workshop2.get_name(), "Hot Chocolate Stand")
        workshop2.set_name("Hot Chocolate and Marshmallows")
        self.assertEqual(workshop2.get_name(), "Hot Chocolate and Marshmallows")

        self.assertEqual(workshop2.get_location(), "Santa Claus Village, Main Road 12, North Pole")
        workshop2.set_location("Santa Claus Village, Main Road 14, North Pole")
        self.assertEqual(workshop2.get_location(), "Santa Claus Village, Main Road 14, North Pole")

        self.assertEqual(workshop2.get_product_type(), "hot chocolate")
        workshop2.set_product_type("hot chocolate and marshmallows")
        self.assertEqual(workshop2.get_product_type(), "hot chocolate and marshmallows")

        self.assertEqual(workshop2.get_number_of_elves(), 1)
        workshop2.set_number_of_elves(0)
        self.assertEqual(workshop2.get_number_of_elves(), 0)
    def test_equal_workshop(self):
        workshop1 = Workshop("Reindeer Inn", "Santa Claus Village, Glittering Road 12, North Pole", 'None', 0)
        workshop2 = Workshop("Reindeer Field", "Santa Claus Village, Glittering Road 12, North Pole", 'None', 0)
        self.assertNotEqual(workshop1, workshop2)
        workshop3 = Workshop("Reindeer Inn", "Santa Claus Village, Glittering Road 29, North Pole", 'None', 12)
        self.assertEqual(workshop1, workshop3)

    def test_workshop_evaluation(self):
        workshop2 = Workshop("Hot Chocolate Stand", "Santa Claus Village, Main Road 12, North Pole", 'hot chocolate', 1)
        number_of_days = 5

        evaluator = WorkshopEvaluation(workshop2, number_of_days)

        self.assertEqual(evaluator.get_min_products(), 50)
        self.assertEqual(evaluator.get_max_products(), 75)
        self.assertEqual(evaluator.get_street_name(), "Main Road 12")
        self.assertEqual(evaluator.get_workshop(), workshop2)
        self.assertEqual(evaluator.get_number_of_days(), number_of_days)

        workshop2 = Workshop("Gingerbread House", "Santa Claus Village, Main Road 12, North Pole", 'gingerbread', 116)
        number_of_days = 12

        evaluator = WorkshopEvaluation(workshop2, number_of_days)

        self.assertEqual(evaluator.get_min_products(), 13920)
        self.assertEqual(evaluator.get_max_products(), 20880)
