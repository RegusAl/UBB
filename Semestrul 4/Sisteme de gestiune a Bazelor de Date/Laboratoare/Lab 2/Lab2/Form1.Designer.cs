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
            this.parentTable = new System.Windows.Forms.DataGridView();
            this.parentTableLabel = new System.Windows.Forms.Label();
            this.childTable = new System.Windows.Forms.DataGridView();
            this.childTableLabel = new System.Windows.Forms.Label();
            this.insertButton = new System.Windows.Forms.Button();
            this.deleteButton = new System.Windows.Forms.Button();
            this.updateButton = new System.Windows.Forms.Button();
            this.textBoxesPanel = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.parentTable)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.childTable)).BeginInit();
            this.SuspendLayout();
            // 
            // parentTable
            // 
            this.parentTable.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.parentTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.parentTable.Location = new System.Drawing.Point(16, 44);
            this.parentTable.Margin = new System.Windows.Forms.Padding(4);
            this.parentTable.Name = "parentTable";
            this.parentTable.RowHeadersWidth = 51;
            this.parentTable.Size = new System.Drawing.Size(469, 614);
            this.parentTable.TabIndex = 0;
            this.parentTable.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.parentTable_CellClick);
            // 
            // parentTableLabel
            // 
            this.parentTableLabel.AutoSize = true;
            this.parentTableLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.parentTableLabel.Location = new System.Drawing.Point(13, 9);
            this.parentTableLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.parentTableLabel.Name = "parentTableLabel";
            this.parentTableLabel.Size = new System.Drawing.Size(152, 29);
            this.parentTableLabel.TabIndex = 1;
            this.parentTableLabel.Text = "Parent Table";
            // 
            // childTable
            // 
            this.childTable.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.childTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.childTable.GridColor = System.Drawing.SystemColors.Control;
            this.childTable.Location = new System.Drawing.Point(524, 44);
            this.childTable.Margin = new System.Windows.Forms.Padding(4);
            this.childTable.Name = "childTable";
            this.childTable.RowHeadersWidth = 51;
            this.childTable.Size = new System.Drawing.Size(707, 276);
            this.childTable.TabIndex = 2;
            this.childTable.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.childTable_CellClick);
            // 
            // childTableLabel
            // 
            this.childTableLabel.AutoSize = true;
            this.childTableLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.childTableLabel.Location = new System.Drawing.Point(519, 9);
            this.childTableLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.childTableLabel.Name = "childTableLabel";
            this.childTableLabel.Size = new System.Drawing.Size(158, 29);
            this.childTableLabel.TabIndex = 3;
            this.childTableLabel.Text = "children table";
            // 
            // insertButton
            // 
            this.insertButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.insertButton.Location = new System.Drawing.Point(985, 400);
            this.insertButton.Margin = new System.Windows.Forms.Padding(4);
            this.insertButton.Name = "insertButton";
            this.insertButton.Size = new System.Drawing.Size(227, 39);
            this.insertButton.TabIndex = 10;
            this.insertButton.Text = "Insert";
            this.insertButton.UseVisualStyleBackColor = true;
            this.insertButton.Click += new System.EventHandler(this.insertButton_Click);
            // 
            // deleteButton
            // 
            this.deleteButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.deleteButton.Location = new System.Drawing.Point(985, 522);
            this.deleteButton.Margin = new System.Windows.Forms.Padding(4);
            this.deleteButton.Name = "deleteButton";
            this.deleteButton.Size = new System.Drawing.Size(227, 39);
            this.deleteButton.TabIndex = 12;
            this.deleteButton.Text = "Delete";
            this.deleteButton.UseVisualStyleBackColor = true;
            this.deleteButton.Click += new System.EventHandler(this.deleteButton_Click);
            // 
            // updateButton
            // 
            this.updateButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.updateButton.Location = new System.Drawing.Point(985, 459);
            this.updateButton.Margin = new System.Windows.Forms.Padding(4);
            this.updateButton.Name = "updateButton";
            this.updateButton.Size = new System.Drawing.Size(227, 39);
            this.updateButton.TabIndex = 13;
            this.updateButton.Text = "Update";
            this.updateButton.UseVisualStyleBackColor = true;
            this.updateButton.Click += new System.EventHandler(this.updateButton_Click);
            // 
            // textBoxesPanel
            // 
            this.textBoxesPanel.Location = new System.Drawing.Point(524, 350);
            this.textBoxesPanel.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxesPanel.Name = "textBoxesPanel";
            this.textBoxesPanel.Size = new System.Drawing.Size(421, 308);
            this.textBoxesPanel.TabIndex = 14;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.ClientSize = new System.Drawing.Size(1267, 673);
            this.Controls.Add(this.textBoxesPanel);
            this.Controls.Add(this.updateButton);
            this.Controls.Add(this.deleteButton);
            this.Controls.Add(this.insertButton);
            this.Controls.Add(this.childTableLabel);
            this.Controls.Add(this.childTable);
            this.Controls.Add(this.parentTableLabel);
            this.Controls.Add(this.parentTable);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "App";
            ((System.ComponentModel.ISupportInitialize)(this.parentTable)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.childTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView parentTable;
        private System.Windows.Forms.Label parentTableLabel;
        private System.Windows.Forms.DataGridView childTable;
        private System.Windows.Forms.Label childTableLabel;
        private System.Windows.Forms.Button insertButton;
        private System.Windows.Forms.Button deleteButton;
        private System.Windows.Forms.Button updateButton;
        private System.Windows.Forms.Panel textBoxesPanel;
    }
}

