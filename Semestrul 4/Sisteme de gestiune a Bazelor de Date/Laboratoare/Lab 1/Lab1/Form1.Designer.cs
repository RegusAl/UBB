using System;
using System.Windows.Forms;

namespace Lab1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnConnectDB = new System.Windows.Forms.Button();
            this.dataGridViewParent = new System.Windows.Forms.DataGridView();
            this.dataGridViewChild = new System.Windows.Forms.DataGridView();
            this.textBoxNume = new System.Windows.Forms.TextBox();
            this.Nume = new System.Windows.Forms.Label();
            this.Pret = new System.Windows.Forms.Label();
            this.Stoc = new System.Windows.Forms.Label();
            this.Categorie = new System.Windows.Forms.Label();
            this.textBoxPret = new System.Windows.Forms.TextBox();
            this.textBoxStoc = new System.Windows.Forms.TextBox();
            this.textBoxCategorie = new System.Windows.Forms.TextBox();
            this.addProdus = new System.Windows.Forms.Button();
            this.deleteProdus = new System.Windows.Forms.Button();
            this.updateProduct = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewParent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewChild)).BeginInit();
            this.SuspendLayout();
            // 
            // btnConnectDB
            // 
            this.btnConnectDB.Location = new System.Drawing.Point(470, 477);
            this.btnConnectDB.Name = "btnConnectDB";
            this.btnConnectDB.Size = new System.Drawing.Size(75, 23);
            this.btnConnectDB.TabIndex = 0;
            this.btnConnectDB.Text = "Connect";
            this.btnConnectDB.UseVisualStyleBackColor = true;
            this.btnConnectDB.Click += new System.EventHandler(this.btnConnectDB_OnClick);
            // 
            // dataGridViewParent
            // 
            this.dataGridViewParent.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewParent.Location = new System.Drawing.Point(25, 35);
            this.dataGridViewParent.Name = "dataGridViewParent";
            this.dataGridViewParent.RowHeadersWidth = 51;
            this.dataGridViewParent.RowTemplate.Height = 24;
            this.dataGridViewParent.Size = new System.Drawing.Size(457, 411);
            this.dataGridViewParent.TabIndex = 1;
            this.dataGridViewParent.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewParent_OnCellClick);
            // 
            // dataGridViewChild
            // 
            this.dataGridViewChild.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewChild.Location = new System.Drawing.Point(546, 183);
            this.dataGridViewChild.Name = "dataGridViewChild";
            this.dataGridViewChild.RowHeadersWidth = 51;
            this.dataGridViewChild.RowTemplate.Height = 24;
            this.dataGridViewChild.Size = new System.Drawing.Size(413, 263);
            this.dataGridViewChild.TabIndex = 2;
            // 
            // textBoxNume
            // 
            this.textBoxNume.Location = new System.Drawing.Point(546, 54);
            this.textBoxNume.Name = "textBoxNume";
            this.textBoxNume.Size = new System.Drawing.Size(100, 22);
            this.textBoxNume.TabIndex = 3;
            // 
            // Nume
            // 
            this.Nume.AutoSize = true;
            this.Nume.Location = new System.Drawing.Point(574, 35);
            this.Nume.Name = "Nume";
            this.Nume.Size = new System.Drawing.Size(43, 16);
            this.Nume.TabIndex = 4;
            this.Nume.Text = "Nume";
            // 
            // Pret
            // 
            this.Pret.AutoSize = true;
            this.Pret.Location = new System.Drawing.Point(682, 35);
            this.Pret.Name = "Pret";
            this.Pret.Size = new System.Drawing.Size(31, 16);
            this.Pret.TabIndex = 5;
            this.Pret.Text = "Pret";
            // 
            // Stoc
            // 
            this.Stoc.AutoSize = true;
            this.Stoc.Location = new System.Drawing.Point(788, 35);
            this.Stoc.Name = "Stoc";
            this.Stoc.Size = new System.Drawing.Size(34, 16);
            this.Stoc.TabIndex = 6;
            this.Stoc.Text = "Stoc";
            // 
            // Categorie
            // 
            this.Categorie.AutoSize = true;
            this.Categorie.Location = new System.Drawing.Point(872, 35);
            this.Categorie.Name = "Categorie";
            this.Categorie.Size = new System.Drawing.Size(66, 16);
            this.Categorie.TabIndex = 7;
            this.Categorie.Text = "Categorie";
            // 
            // textBoxPret
            // 
            this.textBoxPret.Location = new System.Drawing.Point(652, 54);
            this.textBoxPret.Name = "textBoxPret";
            this.textBoxPret.Size = new System.Drawing.Size(95, 22);
            this.textBoxPret.TabIndex = 8;
            // 
            // textBoxStoc
            // 
            this.textBoxStoc.Location = new System.Drawing.Point(753, 54);
            this.textBoxStoc.Name = "textBoxStoc";
            this.textBoxStoc.Size = new System.Drawing.Size(100, 22);
            this.textBoxStoc.TabIndex = 9;
            // 
            // textBoxCategorie
            // 
            this.textBoxCategorie.Location = new System.Drawing.Point(859, 54);
            this.textBoxCategorie.Name = "textBoxCategorie";
            this.textBoxCategorie.Size = new System.Drawing.Size(100, 22);
            this.textBoxCategorie.TabIndex = 10;
            // 
            // addProdus
            // 
            this.addProdus.Location = new System.Drawing.Point(577, 111);
            this.addProdus.Name = "addProdus";
            this.addProdus.Size = new System.Drawing.Size(100, 38);
            this.addProdus.TabIndex = 11;
            this.addProdus.Text = "Adaugare";
            this.addProdus.UseVisualStyleBackColor = true;
            this.addProdus.Click += new System.EventHandler(this.addProdus_Click);
            // 
            // deleteProdus
            // 
            this.deleteProdus.Location = new System.Drawing.Point(701, 111);
            this.deleteProdus.Name = "deleteProdus";
            this.deleteProdus.Size = new System.Drawing.Size(103, 38);
            this.deleteProdus.TabIndex = 12;
            this.deleteProdus.Text = "Stergere";
            this.deleteProdus.UseVisualStyleBackColor = true;
            this.deleteProdus.Click += new System.EventHandler(this.deleteProdus_Click);
            // 
            // updateProduct
            // 
            this.updateProduct.Location = new System.Drawing.Point(825, 112);
            this.updateProduct.Name = "updateProduct";
            this.updateProduct.Size = new System.Drawing.Size(103, 37);
            this.updateProduct.TabIndex = 13;
            this.updateProduct.Text = "Update";
            this.updateProduct.UseVisualStyleBackColor = true;
            this.updateProduct.Click += new System.EventHandler(this.updateProduct_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(217, 449);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 16);
            this.label1.TabIndex = 14;
            this.label1.Text = "Furnizori";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(724, 449);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 16);
            this.label2.TabIndex = 15;
            this.label2.Text = "Produse";
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(1027, 512);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.updateProduct);
            this.Controls.Add(this.deleteProdus);
            this.Controls.Add(this.addProdus);
            this.Controls.Add(this.textBoxCategorie);
            this.Controls.Add(this.textBoxStoc);
            this.Controls.Add(this.textBoxPret);
            this.Controls.Add(this.Categorie);
            this.Controls.Add(this.Stoc);
            this.Controls.Add(this.Pret);
            this.Controls.Add(this.Nume);
            this.Controls.Add(this.textBoxNume);
            this.Controls.Add(this.dataGridViewChild);
            this.Controls.Add(this.dataGridViewParent);
            this.Controls.Add(this.btnConnectDB);
            this.Name = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewParent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewChild)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        #endregion

        private Button btnConnectDB;
        private DataGridView dataGridViewParent;
        private DataGridView dataGridViewChild;
        private TextBox textBoxNume;
        private Label Nume;
        private Label Pret;
        private Label Stoc;
        private Label Categorie;
        private TextBox textBoxPret;
        private TextBox textBoxStoc;
        private TextBox textBoxCategorie;
        private Button addProdus;
        private Button deleteProdus;
        private Button updateProduct;
        private Label label1;
        private Label label2;
    }
}

