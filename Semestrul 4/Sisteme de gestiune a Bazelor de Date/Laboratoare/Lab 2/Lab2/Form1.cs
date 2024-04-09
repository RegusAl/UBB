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
using System.Configuration;
using System.Data.SqlTypes;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Lab1
{
    public partial class Form1 : Form
    {
        static string connectionString = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
        SqlConnection con = new SqlConnection(connectionString);

        private readonly SqlDataAdapter da = new SqlDataAdapter();
        private readonly DataSet dsParentTable = new DataSet();
        private readonly DataSet dsChildTable = new DataSet();
        private readonly BindingSource bsParentTable = new BindingSource();
        private readonly BindingSource bsChildTable = new BindingSource();

        private int selectedParentID = -1;
        private int selectedChildID = -1;

        private string parentTableName = ConfigurationManager.AppSettings["ParentTable"];
        private string parentIDColumn = ConfigurationManager.AppSettings["ParentIDColumn"];

        private string childTableName = ConfigurationManager.AppSettings["ChildTable"];
        private string childIDColumn = ConfigurationManager.AppSettings["ChildIDColumn"];

        private string[] childColumns = ConfigurationManager.AppSettings["ChildColumns"].Split(',');
        private string[] childParams =ConfigurationManager.AppSettings["ChildParameters"].Split(',');

        private string childUpdateQuery = ConfigurationManager.AppSettings["ChildUpdateQuery"];
        private string childDeleteQuery =ConfigurationManager.AppSettings["ChildDeleteQuery"];

        private IDictionary<string, System.Windows.Forms.TextBox> textBoxes = new Dictionary<string, System.Windows.Forms.TextBox>();

        public Form1()
        {
            InitializeComponent();

            con.Open();

            string parentSelectQuery = ConfigurationManager.AppSettings["ParentSelectQuery"];
            da.SelectCommand = new SqlCommand(parentSelectQuery, con);
            dsParentTable.Clear();
            da.Fill(dsParentTable);

            parentTable.DataSource = dsParentTable.Tables[0];
            bsParentTable.DataSource = dsParentTable.Tables[0];

            int pointX = 10;
            int pointY = 10;

            foreach (string childColumn in childColumns)
            {
                if (childColumn != parentIDColumn)
                {
                    var label = new Label
                    {
                        Text = childColumn,
                        Location = new Point(pointX, pointY),
                    };
                    var txtBox = new System.Windows.Forms.TextBox
                    {
                        Location = new Point(pointX,pointY+label.Height),
                        Size = new System.Drawing.Size(500, 30)
                    };

                    pointY += 50;

                    textBoxesPanel.Controls.Add(label);
                    textBoxesPanel.Controls.Add(txtBox);
                    textBoxes.Add(childColumn, txtBox);
                }
            }

            parentTableLabel.Text = parentTableName;
            childTableLabel.Text = childTableName;

            parentTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            parentTable.MultiSelect = false;
            parentTable.ReadOnly = true;
            parentTable.AllowUserToResizeRows = false;
            parentTable.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            parentTable.RowHeadersVisible = false;

            childTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            childTable.MultiSelect = false;
            childTable.ReadOnly = true;
            childTable.AllowUserToResizeRows = false;
            childTable.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            childTable.RowHeadersVisible = false;

        }

        private void refreshChildTable()
        {
            string childSelectQuery = ConfigurationManager.AppSettings["ChildSelectQuery"];
            da.SelectCommand = new SqlCommand(childSelectQuery, con);
            da.SelectCommand.Parameters.AddWithValue("@" + parentIDColumn, selectedParentID);

            dsChildTable.Clear();
            da.Fill(dsChildTable);

            childTable.DataSource = dsChildTable.Tables[0];
            bsChildTable.DataSource = dsChildTable.Tables[0];
        }

        private void parentTable_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || parentTable.Rows[e.RowIndex].Cells[0].Value.ToString() == "")
            {
                selectedParentID = -1;
                return;
            }
            selectedParentID = int.Parse(parentTable.Rows[e.RowIndex].Cells[0].Value.ToString());

            refreshChildTable();
        }

        private void childTable_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                var selectedRow = childTable.Rows[e.RowIndex];
                selectedChildID = int.Parse(selectedRow.Cells[0].Value.ToString());


                if (e.RowIndex < 0 || selectedRow.Cells[0].Value == "")
                {
                    selectedChildID = -1;
                    foreach (var box in textBoxes.Values)
                    {
                        box.Text = "";
                    }
                    return;
                }

                int i = 1;
                foreach (var column in childColumns)
                {
                    if (column != parentIDColumn)
                    {
                        textBoxes[column].Text = selectedRow.Cells[i].Value.ToString();
                        i++;
                    }
                }
            } 
            catch
            {
                MessageBox.Show("Selectati o casuta valida din tabela copil!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void insertButton_Click(object sender, EventArgs e)
        {
            try {

                if (selectedParentID == -1)
                {
                    MessageBox.Show("Selectati o casuta valida din tabela parinte!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                foreach (var box in textBoxes.Values)
                {
                    if (box.Text == "")
                    {
                        MessageBox.Show("Nu se accepta campuri goale", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                }

                string childInsertQuery = ConfigurationManager.AppSettings["ChildInsertQuery"];
                da.InsertCommand = new SqlCommand(childInsertQuery, con);

                for (int i = 0; i < childColumns.Length; i++)
                {
                    if (childColumns[i] != parentIDColumn)
                    {
                        Console.WriteLine(textBoxes[childColumns[i]].Text);

                        da.InsertCommand.Parameters.AddWithValue(childParams[i], textBoxes[childColumns[i]].Text);
                    }
                }

                da.InsertCommand.Parameters.AddWithValue("@" + parentIDColumn, selectedParentID);
                da.InsertCommand.ExecuteNonQuery();
                refreshChildTable();

            }
            catch (SqlException ex)
            {
                MessageBox.Show("Eroare la inserare", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            try
            {
                if (selectedChildID == -1)
                {
                    MessageBox.Show("Selectati o casuta valida din tabela copil! ", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                foreach (var box in textBoxes.Values)
                {
                    if (box.Text == "")
                    {
                        MessageBox.Show("Nu se accepta campuri goale", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                }

                da.UpdateCommand = new SqlCommand(childUpdateQuery, con);

                for (int i = 0; i < childColumns.Length; i++)
                {
                    if (childColumns[i] != parentIDColumn)
                    {
                        da.UpdateCommand.Parameters.AddWithValue(childParams[i], textBoxes[childColumns[i]].Text);
                    }
                }
                da.UpdateCommand.Parameters.AddWithValue("@" + childIDColumn, selectedChildID);

                da.UpdateCommand.ExecuteNonQuery();
                refreshChildTable();

            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            try
            {
                if (selectedChildID == -1)
                {
                    MessageBox.Show("Please select a student first!", "Deletion Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                da.DeleteCommand = new SqlCommand(childDeleteQuery, con);
                da.DeleteCommand.Parameters.Add("@" + childIDColumn, SqlDbType.Int).Value = selectedChildID;
                da.DeleteCommand.ExecuteNonQuery();
                refreshChildTable();

            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
      
        }
    }
}
