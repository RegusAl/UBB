using Microsoft.Data.SqlClient;
using System.Data;

namespace Subiect1
{
    public partial class Form1 : Form
    {

        string connectionString = "Server=ALBERT;Database=SGBD_Problema3;Integrated Security=true;TrustServerCertificate=true;";
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

                    parentAdapter.SelectCommand = new SqlCommand("SELECT * FROM InghetatePreferate;", connection);
                    childAdapter.SelectCommand = new SqlCommand("SELECT * FROM Copii;", connection);

                    parentAdapter.Fill(ds, "InghetatePreferate");
                    childAdapter.Fill(ds, "Copii");

                    parentBS.DataSource = ds.Tables["InghetatePreferate"];
                    dataGridParent.DataSource = parentBS;

                    DataColumn parentColumn = ds.Tables["InghetatePreferate"].Columns["IPid"];
                    DataColumn childColumn = ds.Tables["Copii"].Columns["IPid"];

                    DataRelation relation = new DataRelation("FK_InghetatePreferate_Copii",
                       parentColumn, childColumn);

                    ds.Relations.Add(relation);

                    childBS.DataSource = parentBS;
                    childBS.DataMember = "FK_InghetatePreferate_Copii";
                    dataGridChild.DataSource = childBS;

                    txtNume.DataBindings.Add("Text", childBS, "Nume");
                    txtPrenume.DataBindings.Add("Text", childBS, "Prenume");
                    txtGen.DataBindings.Add("Text", childBS, "Gen");
                    txtVarsta.DataBindings.Add("Text", childBS, "Varsta");
                    txtInghetata.DataBindings.Add("Text", childBS, "IPid");


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
                using (SqlConnection conn = new SqlConnection(connectionString))
                {
                    conn.Open();
                    string addQuery = "INSERT INTO Copii(Nume, Prenume, Gen, Varsta, IPid) " +
                        "VALUES (@Nume, @Prenume, @Gen, @Varsta, @IPid)";
                    SqlCommand cmd = new SqlCommand(addQuery, conn);
                    cmd.Parameters.AddWithValue("@Nume", txtNume.Text);
                    cmd.Parameters.AddWithValue("@Prenume", txtPrenume.Text);
                    cmd.Parameters.AddWithValue("@Gen", txtGen.Text);
                    cmd.Parameters.AddWithValue("@Varsta", txtVarsta.Text);
                    cmd.Parameters.AddWithValue("@IPid", txtInghetata.Text);


                    childAdapter.InsertCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.InsertCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Copii"))
                        ds.Tables["Copii"].Clear();
                    childAdapter.Fill(ds, "Copii");
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
                    string deleteQuery = "Delete From Copii Where Cid = @Cid";
                    SqlCommand cmd = new SqlCommand(deleteQuery, conn);
                    cmd.Parameters.AddWithValue("Cid", dataGridChild.CurrentRow.Cells["Cid"].Value.ToString());
                    childAdapter.DeleteCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.DeleteCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Copii"))
                        ds.Tables["Copii"].Clear();
                    childAdapter.Fill(ds, "Copii");
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
                    string updateQuery = "Update Copii SET Nume = @Nume, Prenume = @Prenume, Gen = @Gen, Varsta = @Varsta WHERE Cid = @Cid;";

                    SqlCommand cmd = new SqlCommand(updateQuery, conn);
                    cmd.Parameters.AddWithValue("@Nume", txtNume.Text);
                    cmd.Parameters.AddWithValue("@Prenume", txtPrenume.Text);
                    cmd.Parameters.AddWithValue("@Gen", txtGen.Text);
                    cmd.Parameters.AddWithValue("@Varsta", txtVarsta.Text);
                    cmd.Parameters.AddWithValue("@Cid", dataGridChild.CurrentRow.Cells["Cid"].Value.ToString());
                    childAdapter.UpdateCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.UpdateCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Copii"))
                        ds.Tables["Copii"].Clear();
                    childAdapter.Fill(ds, "Copii");

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
