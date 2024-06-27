using Microsoft.Data.SqlClient;
using System.Data;

namespace Subiect1
{
    public partial class Form1 : Form
    {

        string connectionString = "Server=ALBERT;Database=Practic;Integrated Security=true;TrustServerCertificate=true;";
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

                    parentAdapter.SelectCommand = new SqlCommand("SELECT * FROM Muzee;", connection);
                    childAdapter.SelectCommand = new SqlCommand("SELECT * FROM Tablouri;", connection);

                    parentAdapter.Fill(ds, "Muzee");
                    childAdapter.Fill(ds, "Tablouri");

                    parentBS.DataSource = ds.Tables["Muzee"];
                    dataGridParent.DataSource = parentBS;

                    DataColumn parentColumn = ds.Tables["Muzee"].Columns["Mid"];
                    DataColumn childColumn = ds.Tables["Tablouri"].Columns["Mid"];

                    DataRelation relation = new DataRelation("FK_Muzeu_Tablouri",
                       parentColumn, childColumn);

                    ds.Relations.Add(relation);

                    childBS.DataSource = parentBS;
                    childBS.DataMember = "FK_Muzeu_Tablouri";
                    dataGridChild.DataSource = childBS;

                    txtDenumire.DataBindings.Add("Text", childBS, "Denumire");
                    txtAn.DataBindings.Add("Text", childBS, "AnPictura");
                    txtDimensiune.DataBindings.Add("Text", childBS, "Dimensiune");
                    txtMuzeu.DataBindings.Add("Text", childBS, "Mid");
                    txtPictor.DataBindings.Add("Text", childBS, "Pid");

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
                    string addQuery = "INSERT INTO Tablouri(Denumire, AnPictura, Dimensiune, Mid, Pid) " +
                        "VALUES (@Denumire, @AnPictura, @Dimensiune, @Mid, @Pid)";
                    SqlCommand cmd = new SqlCommand(addQuery, conn);
                    cmd.Parameters.AddWithValue("@Denumire", txtDenumire.Text);
                    cmd.Parameters.AddWithValue("@AnPictura", txtAn.Text);
                    cmd.Parameters.AddWithValue("Dimensiune", txtDimensiune.Text);
                    cmd.Parameters.AddWithValue("@Mid", txtMuzeu.Text);
                    cmd.Parameters.AddWithValue("@Pid", txtPictor.Text);

                    childAdapter.InsertCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.InsertCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Tablouri"))
                        ds.Tables["Tablouri"].Clear();
                    childAdapter.Fill(ds, "Tablouri");
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
                    string deleteQuery = "Delete From Tablouri Where Tid = @Tid";
                    SqlCommand cmd = new SqlCommand(deleteQuery, conn);
                    cmd.Parameters.AddWithValue("Tid", dataGridChild.CurrentRow.Cells["Tid"].Value.ToString());
                    childAdapter.DeleteCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.DeleteCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Tablouri"))
                        ds.Tables["Tablouri"].Clear();
                    childAdapter.Fill(ds, "Tablouri");
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
                    string updateQuery = "Update Tablouri SET Denumire = @Denumire, AnPictura = @AnPictura, Dimensiune = @Dimensiune, Pid = @Pid WHERE Tid=@Tid;";

                    SqlCommand cmd = new SqlCommand(updateQuery, conn);
                    cmd.Parameters.AddWithValue("@Denumire", txtDenumire.Text);
                    cmd.Parameters.AddWithValue("@AnPictura", txtAn.Text);
                    cmd.Parameters.AddWithValue("@Dimensiune", txtDimensiune.Text);
                    cmd.Parameters.AddWithValue("@Pid", txtPictor.Text);

                    cmd.Parameters.AddWithValue("@Tid", dataGridChild.CurrentRow.Cells["Tid"].Value.ToString());
                    childAdapter.UpdateCommand = cmd;
                    childAdapter.SelectCommand.Connection = conn;

                    childAdapter.UpdateCommand.ExecuteNonQuery();

                    if (ds.Tables.Contains("Tablouri"))
                        ds.Tables["Tablouri"].Clear();
                    childAdapter.Fill(ds, "Tablouri");

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
