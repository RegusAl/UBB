using Microsoft.Data.SqlClient;
using System.Data;

namespace Subiect1
{
    public partial class Form1 : Form
    {

        string connectionString = "Server=ALBERT;Database=SGBD_Problema1;Integrated Security=true;TrustServerCertificate=true;";
        DataSet ds = new DataSet();
        SqlDataAdapter parentAdapter = new SqlDataAdapter();
        SqlDataAdapter childAdapter = new SqlDataAdapter();
        BindingSource parentBS = new BindingSource();
        BindingSource childBS = new BindingSource();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    parentAdapter.SelectCommand = new SqlCommand("SELECT * FROM Cofetarii;", connection);
                    childAdapter.SelectCommand = new SqlCommand("SELECT * FROM Briose;", connection);

                    parentAdapter.Fill(ds, "Cofetarii");
                    childAdapter.Fill(ds, "Briose");

                    parentBS.DataSource = ds.Tables["Cofetarii"];
                    dataGridParent.DataSource = parentBS;

                    DataColumn parentColumn = ds.Tables["Cofetarii"].Columns["cod_cofetarie"];
                    DataColumn childColumn = ds.Tables["Briose"].Columns["cod_cofetarie"];

                    DataRelation relation = new DataRelation("FK_Briose_Cofetarie",
                       parentColumn, childColumn);

                    ds.Relations.Add(relation);

                    childBS.DataSource = parentBS;
                    childBS.DataMember = "FK_Briose_Cofetarie";
                    dataGridChild.DataSource = childBS;

                    txtNume.DataBindings.Add("Text", childBS, "nume_briosa");
                    txtDescriere.DataBindings.Add("Text", childBS, "descriere");
                    txtPret.DataBindings.Add("Text", childBS, "pret");
                    txtCofetarie.DataBindings.Add("Text", childBS, "cod_cofetarie");

                    connection.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                using(SqlConnection conn = new SqlConnection(connectionString))
                {
                    conn.Open();
                    string addQuery = "INSERT INTO Briose(nume_briosa, descriere, pret, cod_cofetarie) " +
                        "VALUES (@nume, @descriere, @pret, @cod_cofetarie)";
                    SqlCommand cmd = new SqlCommand(addQuery, conn);
                    cmd.Parameters.AddWithValue("@nume", txtNume.Text);
                    cmd.Parameters.AddWithValue("@descriere", txtDescriere.Text);
                    cmd.Parameters.AddWithValue("pret", txtPret.Text);
                    cmd.Parameters.AddWithValue("@cod_cofetarie", txtCofetarie.Text);

                    childAdapter.InsertCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.InsertCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Briose"))
                        ds.Tables["Briose"].Clear();
                    childAdapter.Fill(ds, "Briose");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection conn = new SqlConnection(connectionString))
                {
                    conn.Open();
                    string deleteQuery = "Delete From Briose Where cod_briosa = @cod";
                    SqlCommand cmd = new SqlCommand(deleteQuery, conn);
                    cmd.Parameters.AddWithValue("cod", dataGridChild.CurrentRow.Cells["cod_briosa"].Value.ToString());
                    childAdapter.DeleteCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.DeleteCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Briose"))
                        ds.Tables["Briose"].Clear();
                    childAdapter.Fill(ds, "Briose");
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection conn = new SqlConnection(connectionString))
                {
                    conn.Open();
                    string updateQuery = "Update Briose SET nume_briosa = @nume, descriere=@descriere,pret=@pret WHERE cod_briosa=@cod;";

                    SqlCommand cmd = new SqlCommand(updateQuery, conn);
                    cmd.Parameters.AddWithValue("@nume", txtNume.Text);
                    cmd.Parameters.AddWithValue("@descriere", txtDescriere.Text);
                    cmd.Parameters.AddWithValue("@pret", txtPret.Text);
                    cmd.Parameters.AddWithValue("@cod", dataGridChild.CurrentRow.Cells["cod_briosa"].Value.ToString());
                    childAdapter.UpdateCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.UpdateCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Briose"))
                        ds.Tables["Briose"].Clear();
                    childAdapter.Fill(ds, "Briose");

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
    }
