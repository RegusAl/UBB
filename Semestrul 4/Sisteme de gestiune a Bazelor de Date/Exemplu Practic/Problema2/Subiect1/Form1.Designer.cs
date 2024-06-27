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
            txtTitlu = new TextBox();
            txtAnLansare = new TextBox();
            txtDurata = new TextBox();
            txtArtist = new TextBox();
            btnAdd = new Button();
            btnDelete = new Button();
            btnUpdate = new Button();
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
            // txtTitlu
            // 
            txtTitlu.Location = new Point(588, 258);
            txtTitlu.Name = "txtTitlu";
            txtTitlu.Size = new Size(100, 23);
            txtTitlu.TabIndex = 2;
            // 
            // txtAnLansare
            // 
            txtAnLansare.Location = new Point(588, 302);
            txtAnLansare.Name = "txtAnLansare";
            txtAnLansare.Size = new Size(100, 23);
            txtAnLansare.TabIndex = 3;
            // 
            // txtDurata
            // 
            txtDurata.Location = new Point(588, 348);
            txtDurata.Name = "txtDurata";
            txtDurata.Size = new Size(100, 23);
            txtDurata.TabIndex = 4;
            // 
            // txtArtist
            // 
            txtArtist.Location = new Point(588, 393);
            txtArtist.Name = "txtArtist";
            txtArtist.Size = new Size(100, 23);
            txtArtist.TabIndex = 5;
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
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(807, 547);
            Controls.Add(btnUpdate);
            Controls.Add(btnDelete);
            Controls.Add(btnAdd);
            Controls.Add(txtArtist);
            Controls.Add(txtDurata);
            Controls.Add(txtAnLansare);
            Controls.Add(txtTitlu);
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
        private TextBox txtTitlu;
        private TextBox txtAnLansare;
        private TextBox txtDurata;
        private TextBox txtArtist;
        private Button btnAdd;
        private Button btnDelete;
        private Button btnUpdate;
    }
}
