namespace Subiect1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            dataGridParent = new DataGridView();
            dataGridChild = new DataGridView();
            txtNume = new TextBox();
            txtPrenume = new TextBox();
            txtGen = new TextBox();
            txtVarsta = new TextBox();
            btnAdd = new Button();
            btnDelete = new Button();
            btnUpdate = new Button();
            txtInghetata = new TextBox();
            ((System.ComponentModel.ISupportInitialize)dataGridParent).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dataGridChild).BeginInit();
            SuspendLayout();
            // 
            // dataGridParent
            // 
            dataGridParent.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridParent.Location = new Point(34, 44);
            dataGridParent.Name = "dataGridParent";
            dataGridParent.Size = new Size(325, 342);
            dataGridParent.TabIndex = 0;
            // 
            // dataGridChild
            // 
            dataGridChild.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridChild.Location = new Point(448, 44);
            dataGridChild.Name = "dataGridChild";
            dataGridChild.Size = new Size(240, 176);
            dataGridChild.TabIndex = 1;
            // 
            // txtNume
            // 
            txtNume.Location = new Point(588, 258);
            txtNume.Name = "txtNume";
            txtNume.Size = new Size(100, 23);
            txtNume.TabIndex = 2;
            // 
            // txtPrenume
            // 
            txtPrenume.Location = new Point(588, 302);
            txtPrenume.Name = "txtPrenume";
            txtPrenume.Size = new Size(100, 23);
            txtPrenume.TabIndex = 3;
            // 
            // txtGen
            // 
            txtGen.Location = new Point(588, 348);
            txtGen.Name = "txtGen";
            txtGen.Size = new Size(100, 23);
            txtGen.TabIndex = 4;
            // 
            // txtVarsta
            // 
            txtVarsta.Location = new Point(588, 393);
            txtVarsta.Name = "txtVarsta";
            txtVarsta.Size = new Size(100, 23);
            txtVarsta.TabIndex = 5;
            // 
            // btnAdd
            // 
            btnAdd.Location = new Point(448, 468);
            btnAdd.Name = "btnAdd";
            btnAdd.Size = new Size(75, 23);
            btnAdd.TabIndex = 6;
            btnAdd.Text = "Add";
            btnAdd.UseVisualStyleBackColor = true;
            btnAdd.Click += btnAdd_Click;
            // 
            // btnDelete
            // 
            btnDelete.Location = new Point(532, 468);
            btnDelete.Name = "btnDelete";
            btnDelete.Size = new Size(75, 23);
            btnDelete.TabIndex = 7;
            btnDelete.Text = "Delete";
            btnDelete.UseVisualStyleBackColor = true;
            btnDelete.Click += btnDelete_Click;
            // 
            // btnUpdate
            // 
            btnUpdate.Location = new Point(613, 468);
            btnUpdate.Name = "btnUpdate";
            btnUpdate.Size = new Size(75, 23);
            btnUpdate.TabIndex = 8;
            btnUpdate.Text = "Update";
            btnUpdate.UseVisualStyleBackColor = true;
            btnUpdate.Click += btnUpdate_Click;
            // 
            // txtInghetata
            // 
            txtInghetata.Location = new Point(588, 439);
            txtInghetata.Name = "txtInghetata";
            txtInghetata.Size = new Size(100, 23);
            txtInghetata.TabIndex = 9;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(807, 547);
            Controls.Add(txtInghetata);
            Controls.Add(btnUpdate);
            Controls.Add(btnDelete);
            Controls.Add(btnAdd);
            Controls.Add(txtVarsta);
            Controls.Add(txtGen);
            Controls.Add(txtPrenume);
            Controls.Add(txtNume);
            Controls.Add(dataGridChild);
            Controls.Add(dataGridParent);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridParent).EndInit();
            ((System.ComponentModel.ISupportInitialize)dataGridChild).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DataGridView dataGridParent;
        private DataGridView dataGridChild;
        private TextBox txtNume;
        private TextBox txtPrenume;
        private TextBox txtGen;
        private TextBox txtVarsta;
        private Button btnAdd;
        private Button btnDelete;
        private Button btnUpdate;
        private TextBox txtInghetata;
    }
}
