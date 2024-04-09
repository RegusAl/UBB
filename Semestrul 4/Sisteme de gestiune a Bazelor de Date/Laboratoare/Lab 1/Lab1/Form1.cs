using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1
{
    public partial class Form1 : Form
    {

        SqlConnection connectionString = new SqlConnection("Data Source=ALBERT;Initial Catalog=MagazinSportiv;Integrated Security=True;Encrypt=False");
        DataSet parentDS = new DataSet();
        DataSet childDS = new DataSet();
        SqlDataAdapter parentAdapter = new SqlDataAdapter();
        SqlDataAdapter childAdapter = new SqlDataAdapter();
        BindingSource parentBS = new BindingSource();
        BindingSource childBS = new BindingSource();


        public Form1()
        {
            InitializeComponent();
        }

        private void btnConnectDB_OnClick(object sender, EventArgs e)
        {
            parentAdapter.SelectCommand = new SqlCommand("SELECT * FROM Furnizori", connectionString);
            parentDS.Clear();
            parentAdapter.Fill(parentDS);
            dataGridViewParent.DataSource = parentDS.Tables[0];
            parentBS.DataSource = parentDS.Tables[0];
            parentBS.MoveLast();
        }

        private void dataGridViewParent_OnCellClick(object sender, DataGridViewCellEventArgs e)
        {
                if (dataGridViewParent.Rows[e.RowIndex].Cells[e.ColumnIndex].Value == null)
                {
                    MessageBox.Show("Selectati o celula valida din tabela 'Produse'");
                }

                string idFurnizor = dataGridViewParent.Rows[e.RowIndex].Cells[0].Value.ToString();

                childAdapter.SelectCommand = new SqlCommand("SELECT * FROM Produse WHERE Produse.idFurnizor = " + idFurnizor + "; ", connectionString);
                childDS.Clear();
                childAdapter.Fill(childDS);
                dataGridViewChild.DataSource = childDS.Tables[0];
                childBS.DataSource = childDS.Tables[0];
        }

        private void addProdus_Click(object sender, EventArgs e)
        {
            try
            {
                childAdapter.InsertCommand = new SqlCommand("INSERT INTO Produse(Nume, Pret, Stoc, idFurnizor, idCategorie) VALUES (@numeProdus, @pretProdus, @stocProdus, @idFurnizor, @categorieProdus)", connectionString);

                childAdapter.InsertCommand.Parameters.Add("@numeProdus", SqlDbType.VarChar).Value = textBoxNume.Text;

                childAdapter.InsertCommand.Parameters.Add("@pretProdus", SqlDbType.Int).Value = int.Parse(textBoxPret.Text);

                childAdapter.InsertCommand.Parameters.Add("@stocProdus", SqlDbType.Int).Value = int.Parse(textBoxStoc.Text);

                childAdapter.InsertCommand.Parameters.Add("@idFurnizor", SqlDbType.Int).Value =
                    parentDS.Tables[dataGridViewParent.CurrentCell.ColumnIndex].Rows[dataGridViewParent.CurrentCell.RowIndex][0];

                childAdapter.InsertCommand.Parameters.Add("@categorieProdus", SqlDbType.Int).Value = int.Parse(textBoxCategorie.Text);

                connectionString.Open();
                int ok = childAdapter.InsertCommand.ExecuteNonQuery();
                connectionString.Close();
                childDS.Clear();
                childAdapter.Fill(childDS);

                if (ok >= 1)
                {
                    MessageBox.Show("S-a adaugat cu success!");
                }
            }
            catch(Exception ex) {
                MessageBox.Show(ex.Message);
                connectionString.Close();
            }
        }

        private void deleteProdus_Click(object sender, EventArgs e)
        {
            try
            {
                childAdapter.DeleteCommand = new SqlCommand("DELETE FROM Produse WHERE idProdus = @idProdus;", connectionString);

                childAdapter.DeleteCommand.Parameters.Add("@idProdus", SqlDbType.Int).Value
                    = childDS.Tables[0].Rows[dataGridViewChild.CurrentCell.RowIndex][0];

                connectionString.Open();
                int ok = childAdapter.DeleteCommand.ExecuteNonQuery();
                connectionString.Close();
                childDS.Clear();
                childAdapter.Fill(childDS);

                if (ok >= 1)
                {
                    MessageBox.Show("S-a sters cu success!");
                }
            }
            catch (Exception ex) 
            { 
                MessageBox.Show(ex.Message);
                connectionString.Close();
            }

        }

        private void updateProduct_Click(object sender, EventArgs e)
        {
            try
            {
                childAdapter.UpdateCommand = new SqlCommand("UPDATE Produse SET Nume = @numeProdus, Pret = @pretProdus, Stoc =  @stocProdus, idCategorie = @categorieProdus WHERE Produse.idFurnizor = @idFurnizor", connectionString);

                childAdapter.UpdateCommand.Parameters.Add("@numeProdus", SqlDbType.VarChar).Value = textBoxNume.Text;

                childAdapter.UpdateCommand.Parameters.Add("@pretProdus", SqlDbType.Int).Value = int.Parse(textBoxPret.Text);

                childAdapter.UpdateCommand.Parameters.Add("@stocProdus", SqlDbType.Int).Value = int.Parse(textBoxStoc.Text);

                childAdapter.UpdateCommand.Parameters.Add("@categorieProdus", SqlDbType.Int).Value = int.Parse(textBoxCategorie.Text);

                childAdapter.UpdateCommand.Parameters.Add("@idFurnizor", SqlDbType.Int).Value =
                    parentDS.Tables[dataGridViewParent.CurrentCell.ColumnIndex].Rows[dataGridViewParent.CurrentCell.RowIndex][0];

                connectionString.Open();
                int ok = childAdapter.UpdateCommand.ExecuteNonQuery();
                connectionString.Close();
                childDS.Clear();
                childAdapter.Fill(childDS);

                if (ok >= 1)
                {
                    MessageBox.Show("S-a executat update!");
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                connectionString.Close();
            }
        }
    }
}
