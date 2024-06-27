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
            txtDenumire = new TextBox();
            txtAn = new TextBox();
            txtDimensiune = new TextBox();
            txtMuzeu = new TextBox();
            btnAdd = new Button();
            btnDelete = new Button();
            btnUpdate = new Button();
            Denumire = new Label();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            txtPictor = new TextBox();
            label4 = new Label();
            ((System.ComponentModel.ISupportInitialize)dataGridParent).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dataGridChild).BeginInit();
            SuspendLayout();
            // 
            // dataGridParent
            // 
            dataGridParent.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridParent.Location = new Point(34, 21);
            dataGridParent.Name = "dataGridParent";
            dataGridParent.Size = new Size(387, 233);
            dataGridParent.TabIndex = 0;
            // 
            // dataGridChild
            // 
            dataGridChild.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridChild.Location = new Point(34, 298);
            dataGridChild.Name = "dataGridChild";
            dataGridChild.Size = new Size(678, 217);
            dataGridChild.TabIndex = 1;
            // 
            // txtDenumire
            // 
            txtDenumire.Location = new Point(556, 21);
            txtDenumire.Name = "txtDenumire";
            txtDenumire.Size = new Size(156, 23);
            txtDenumire.TabIndex = 2;
            // 
            // txtAn
            // 
            txtAn.Location = new Point(556, 65);
            txtAn.Name = "txtAn";
            txtAn.Size = new Size(156, 23);
            txtAn.TabIndex = 3;
            // 
            // txtDimensiune
            // 
            txtDimensiune.Location = new Point(556, 111);
            txtDimensiune.Name = "txtDimensiune";
            txtDimensiune.Size = new Size(156, 23);
            txtDimensiune.TabIndex = 4;
            // 
            // txtMuzeu
            // 
            txtMuzeu.Location = new Point(556, 156);
            txtMuzeu.Name = "txtMuzeu";
            txtMuzeu.Size = new Size(156, 23);
            txtMuzeu.TabIndex = 5;
            // 
            // btnAdd
            // 
            btnAdd.Location = new Point(472, 231);
            btnAdd.Name = "btnAdd";
            btnAdd.Size = new Size(75, 23);
            btnAdd.TabIndex = 6;
            btnAdd.Text = "Add";
            btnAdd.UseVisualStyleBackColor = true;
            btnAdd.Click += btnAdd_Click;
            // 
            // btnDelete
            // 
            btnDelete.Location = new Point(556, 231);
            btnDelete.Name = "btnDelete";
            btnDelete.Size = new Size(75, 23);
            btnDelete.TabIndex = 7;
            btnDelete.Text = "Delete";
            btnDelete.UseVisualStyleBackColor = true;
            btnDelete.Click += btnDelete_Click;
            // 
            // btnUpdate
            // 
            btnUpdate.Location = new Point(637, 231);
            btnUpdate.Name = "btnUpdate";
            btnUpdate.Size = new Size(75, 23);
            btnUpdate.TabIndex = 8;
            btnUpdate.Text = "Update";
            btnUpdate.UseVisualStyleBackColor = true;
            btnUpdate.Click += btnUpdate_Click;
            // 
            // Denumire
            // 
            Denumire.AutoSize = true;
            Denumire.Location = new Point(472, 24);
            Denumire.Name = "Denumire";
            Denumire.Size = new Size(59, 15);
            Denumire.TabIndex = 9;
            Denumire.Text = "Denumire";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(472, 68);
            label1.Name = "label1";
            label1.Size = new Size(25, 15);
            label1.TabIndex = 10;
            label1.Text = "An ";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(472, 114);
            label2.Name = "label2";
            label2.Size = new Size(70, 15);
            label2.TabIndex = 11;
            label2.Text = "Dimensiune";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(472, 159);
            label3.Name = "label3";
            label3.Size = new Size(43, 15);
            label3.TabIndex = 12;
            label3.Text = "Muzeu";
            label3.Click += label3_Click;
            // 
            // txtPictor
            // 
            txtPictor.Location = new Point(556, 202);
            txtPictor.Name = "txtPictor";
            txtPictor.Size = new Size(156, 23);
            txtPictor.TabIndex = 13;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(472, 205);
            label4.Name = "label4";
            label4.Size = new Size(51, 15);
            label4.TabIndex = 14;
            label4.Text = "id Pictor";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(807, 547);
            Controls.Add(label4);
            Controls.Add(txtPictor);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(Denumire);
            Controls.Add(btnUpdate);
            Controls.Add(btnDelete);
            Controls.Add(btnAdd);
            Controls.Add(txtMuzeu);
            Controls.Add(txtDimensiune);
            Controls.Add(txtAn);
            Controls.Add(txtDenumire);
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
        private TextBox txtDenumire;
        private TextBox txtAn;
        private TextBox txtDimensiune;
        private TextBox txtMuzeu;
        private Button btnAdd;
        private Button btnDelete;
        private Button btnUpdate;
        private Label Denumire;
        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox txtPictor;
        private Label label4;
    }
}
