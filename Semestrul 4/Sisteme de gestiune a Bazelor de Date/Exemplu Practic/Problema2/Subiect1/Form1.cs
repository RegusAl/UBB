using Microsoft.Data.SqlClient;
using System.Data;

namespace Subiect1
{
    public partial class Form1 : Form
    {

        string connectionString = "Server=ALBERT;Database=SGBD_Problema2;Integrated Security=true;TrustServerCertificate=true;";
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

                    parentAdapter.SelectCommand = new SqlCommand("SELECT * FROM Artisti;", connection);
                    childAdapter.SelectCommand = new SqlCommand("SELECT * FROM Melodii;", connection);

                    parentAdapter.Fill(ds, "Artisti");
                    childAdapter.Fill(ds, "Melodii");

                    parentBS.DataSource = ds.Tables["Artisti"];
                    dataGridParent.DataSource = parentBS;

                    DataColumn parentColumn = ds.Tables["Artisti"].Columns["cod_artist"];
                    DataColumn childColumn = ds.Tables["Melodii"].Columns["cod_artist"];

                    DataRelation relation = new DataRelation("FK_Artisti_Melodii",
                       parentColumn, childColumn);

                    ds.Relations.Add(relation);

                    childBS.DataSource = parentBS;
                    childBS.DataMember = "FK_Artisti_Melodii";
                    dataGridChild.DataSource = childBS;

                    txtTitlu.DataBindings.Add("Text", childBS, "titlu");
                    txtAnLansare.DataBindings.Add("Text", childBS, "an_lansare");
                    txtDurata.DataBindings.Add("Text", childBS, "durata");
                    txtArtist.DataBindings.Add("Text", childBS, "cod_artist");

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
                    string addQuery = "INSERT INTO Melodii(titlu, an_lansare, durata, cod_artist) " +
                        "VALUES (@titlu, @an_lansare, @durata, @cod_artist)";
                    SqlCommand cmd = new SqlCommand(addQuery, conn);
                    cmd.Parameters.AddWithValue("@titlu", txtTitlu.Text);
                    cmd.Parameters.AddWithValue("@an_lansare", txtAnLansare.Text);
                    cmd.Parameters.AddWithValue("@durata", txtDurata.Text);
                    cmd.Parameters.AddWithValue("@cod_artist", txtArtist.Text);

                    childAdapter.InsertCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.InsertCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Melodii"))
                        ds.Tables["Melodii"].Clear();
                    childAdapter.Fill(ds, "Melodii");
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
                    string deleteQuery = "Delete From Melodii Where cod_melodie = @cod";
                    SqlCommand cmd = new SqlCommand(deleteQuery, conn);
                    cmd.Parameters.AddWithValue("cod", dataGridChild.CurrentRow.Cells["cod_melodie"].Value.ToString());
                    childAdapter.DeleteCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.DeleteCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Melodii"))
                        ds.Tables["Melodii"].Clear();
                    childAdapter.Fill(ds, "Melodii");
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
                    string updateQuery = "Update Melodii SET titlu = @titlu, an_lansare=@an_lansare,durata=@durata WHERE cod_melodie=@cod_melodie;";

                    SqlCommand cmd = new SqlCommand(updateQuery, conn);
                    cmd.Parameters.AddWithValue("@titlu", txtTitlu.Text);
                    cmd.Parameters.AddWithValue("@an_lansare", txtAnLansare.Text);
                    cmd.Parameters.AddWithValue("@durata", txtDurata.Text);
                    cmd.Parameters.AddWithValue("@cod_melodie", dataGridChild.CurrentRow.Cells["cod_melodie"].Value.ToString());
                    childAdapter.UpdateCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.UpdateCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Melodii"))
                        ds.Tables["Melodii"].Clear();
                    childAdapter.Fill(ds, "Melodii");

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
    }
