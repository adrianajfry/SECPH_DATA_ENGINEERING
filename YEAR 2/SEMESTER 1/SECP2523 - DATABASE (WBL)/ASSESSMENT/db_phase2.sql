-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3307
-- Generation Time: Jan 26, 2025 at 12:11 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_phase2`
--

-- --------------------------------------------------------

--
-- Table structure for table `boardofdirector`
--

CREATE TABLE `boardofdirector` (
  `bodID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `boardofdirector`
--

INSERT INTO `boardofdirector` (`bodID`) VALUES
(123);

-- --------------------------------------------------------

--
-- Table structure for table `kadaadmin`
--

CREATE TABLE `kadaadmin` (
  `adminID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `kadaadmin`
--

INSERT INTO `kadaadmin` (`adminID`) VALUES
(456);

-- --------------------------------------------------------

--
-- Table structure for table `loan`
--

CREATE TABLE `loan` (
  `loanApplicationID` int(11) NOT NULL,
  `applicationID` int(11) NOT NULL,
  `loanType` enum('Al-Bai','Al-Innah','Baik Pulih Kenderaan','Road Tax dan Insurans','Khas','Karnival Musim Istimewa','Al-Qadrul Hassan') NOT NULL,
  `loanAmount` decimal(10,2) NOT NULL,
  `loanPeriod` int(3) NOT NULL,
  `monthlyInstallment` decimal(10,2) DEFAULT NULL,
  `DOB` date NOT NULL,
  `age` int(2) NOT NULL,
  `bankName` varchar(100) NOT NULL,
  `bankAccountNo` varchar(30) NOT NULL,
  `guarantorName` varchar(100) NOT NULL,
  `guarantorICNo` varchar(14) NOT NULL,
  `guarantorPFNo` varchar(20) NOT NULL,
  `guarantorMemberID` int(11) NOT NULL,
  `guarantorPhoneNo` int(15) NOT NULL,
  `loanPaymentReceipt` text NOT NULL,
  `loanApplicationStatus` enum('Approved','Pending','Rejected') NOT NULL DEFAULT 'Pending'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `loan`
--

INSERT INTO `loan` (`loanApplicationID`, `applicationID`, `loanType`, `loanAmount`, `loanPeriod`, `monthlyInstallment`, `DOB`, `age`, `bankName`, `bankAccountNo`, `guarantorName`, `guarantorICNo`, `guarantorPFNo`, `guarantorMemberID`, `guarantorPhoneNo`, `loanPaymentReceipt`, `loanApplicationStatus`) VALUES
(1001, 3001, 'Al-Innah', 50000.00, 60, 1000.00, '1991-01-01', 34, 'Maybank', '123456789', 'Zainul Abidin', '890101-14-5678', 'PF11223', 101, 123456789, 'Receipt_1001.pdf', 'Approved'),
(1002, 3002, 'Karnival Musim Istimewa', 250000.00, 240, 1500.00, '1992-02-02', 33, 'CIMB Bank', '987654321', 'Chang Wei', '870202-06-1234', 'PF33445', 102, 174567890, 'Receipt_1002.pdf', 'Rejected'),
(1003, 3003, 'Al-Qadrul Hassan', 70000.00, 84, 1200.00, '1993-03-03', 31, 'Public Bank', '112233445', 'Rahmat Amin', '860303-12-4567', 'PF55678', 103, 112233445, 'Receipt_1003.pdf', 'Pending'),
(1004, 3004, 'Baik Pulih Kenderaan', 150000.00, 120, 2500.00, '1994-04-04', 29, 'RHB Bank', '667788990', 'Siti Mariam', '880404-08-7890', 'PF77890', 104, 133344556, 'Receipt_1004.pdf', 'Pending');

-- --------------------------------------------------------

--
-- Table structure for table `membership`
--

CREATE TABLE `membership` (
  `applicationID` int(11) NOT NULL,
  `email` varchar(100) NOT NULL,
  `name` varchar(100) NOT NULL,
  `icNo` varchar(14) NOT NULL,
  `marriageStatus` enum('Single','Married','Divorced','Widowed') NOT NULL,
  `homeAddress` text NOT NULL,
  `homePostcode` int(5) NOT NULL,
  `homeState` varchar(50) NOT NULL,
  `homeCity` varchar(50) NOT NULL,
  `gender` enum('Male','Female') NOT NULL,
  `religion` varchar(20) NOT NULL,
  `race` varchar(20) NOT NULL,
  `monthlySalary` decimal(10,2) NOT NULL,
  `staffNo` varchar(50) NOT NULL,
  `pfNo` varchar(50) NOT NULL,
  `positionGrade` varchar(20) NOT NULL,
  `workAddress` text NOT NULL,
  `workState` varchar(50) NOT NULL,
  `workCity` varchar(50) NOT NULL,
  `workPostcode` int(5) NOT NULL,
  `faxNo` int(15) DEFAULT NULL,
  `phoneNo` int(15) NOT NULL,
  `homePhoneNo` int(15) DEFAULT NULL,
  `entranceFee` decimal(10,2) NOT NULL,
  `shareCapital` decimal(10,2) NOT NULL,
  `feeCapital` decimal(10,2) NOT NULL,
  `memberDeposit` decimal(10,2) NOT NULL,
  `charityFund` decimal(10,2) NOT NULL,
  `fixedSavings` decimal(10,2) NOT NULL,
  `applicationDate` date NOT NULL,
  `applicationStatus` enum('Success','Pending','Rejected') NOT NULL,
  `membershipStatus` enum('Active','Inactive') NOT NULL,
  `approvalDate` date DEFAULT NULL,
  `comment` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `membership`
--

INSERT INTO `membership` (`applicationID`, `email`, `name`, `icNo`, `marriageStatus`, `homeAddress`, `homePostcode`, `homeState`, `homeCity`, `gender`, `religion`, `race`, `monthlySalary`, `staffNo`, `pfNo`, `positionGrade`, `workAddress`, `workState`, `workCity`, `workPostcode`, `faxNo`, `phoneNo`, `homePhoneNo`, `entranceFee`, `shareCapital`, `feeCapital`, `memberDeposit`, `charityFund`, `fixedSavings`, `applicationDate`, `applicationStatus`, `membershipStatus`, `approvalDate`, `comment`) VALUES
(3001, 'arjuna.nirmala@example.com', 'Arjuna Nirmala', '910101145678', 'Married', '123 Jalan Kerinchi', 43000, 'Selangor', 'Kajang', 'Male', 'Islam', 'Malay', 5000.00, 'S12345', 'PF67890', 'Grade 1', '456 Corporate Blvd', 'Selangor', 'Shah Alam', 40000, 31234567, 123456789, 39876543, 50.00, 2000.00, 500.00, 300.00, 100.00, 1000.00, '2025-01-01', 'Success', 'Active', '2025-01-15', 'Approved without issues'),
(3002, 'kasih.cendana@example.com', 'Kasih Cendana', '920202063456', 'Single', '45 Bunga Harum', 10460, 'Penang', 'Georgetown', 'Female', 'Christianity', 'Chinese', 3500.00, 'S67890', 'PF12345', 'Grade 2', '789 Tech Park', 'Penang', 'Butterworth', 12200, 46789100, 174567890, 45566778, 70.00, 1500.00, 300.00, 200.00, 80.00, 800.00, '2024-12-15', 'Success', 'Active', '2024-12-20', 'Application approved quickly'),
(3003, 'aryan.hadi@example.com', 'Aryan Hadi', '930303127890', 'Married', '678 Damansara Hill', 50700, 'Kuala Lumpur', 'Kuala Lumpur', 'Male', 'Islam', 'Malay', 4000.00, 'S23456', 'PF45678', 'Grade 1', '12 Office Ave', 'Kuala Lumpur', 'Kuala Lumpur', 50700, 37654321, 112233445, 38877665, 60.00, 2500.00, 600.00, 500.00, 120.00, 1500.00, '2025-02-10', 'Pending', 'Inactive', NULL, 'Awaiting further documents'),
(3004, 'beatrice.rini@example.com', 'Beatrice Rini', '940404085678', 'Divorced', '90 Riverfront', 80000, 'Johor', 'Johor Bahru', 'Female', 'Hinduism', 'Indian', 4500.00, 'S34567', 'PF67890', 'Grade 3', '34 Business Park', 'Johor', 'Pasir Gudang', 81700, 72233445, 133344556, 71122334, 80.00, 3000.00, 700.00, 400.00, 200.00, 2000.00, '2023-11-05', 'Rejected', 'Inactive', '2023-11-15', 'Application rejected due to missing documents');

-- --------------------------------------------------------

--
-- Table structure for table `reporthub`
--

CREATE TABLE `reporthub` (
  `Month` int(2) NOT NULL,
  `Year` int(4) NOT NULL,
  `adminID` int(11) NOT NULL,
  `bodID` int(11) DEFAULT NULL,
  `memberNo` int(11) DEFAULT NULL,
  `total_membershipApplicationStatus` int(11) DEFAULT NULL,
  `total_loanApplicationStatus` int(11) DEFAULT NULL,
  `total_shareCapital` decimal(12,2) DEFAULT 0.00,
  `total_feeCapital` decimal(12,2) DEFAULT 0.00,
  `total_membersFund` decimal(12,2) DEFAULT 0.00,
  `applicationID` int(11) NOT NULL,
  `loanApplicationID` int(11) NOT NULL,
  `total_loanTypeApplication` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `reporthub`
--

INSERT INTO `reporthub` (`Month`, `Year`, `adminID`, `bodID`, `memberNo`, `total_membershipApplicationStatus`, `total_loanApplicationStatus`, `total_shareCapital`, `total_feeCapital`, `total_membersFund`, `applicationID`, `loanApplicationID`, `total_loanTypeApplication`) VALUES
(1, 2025, 456, 123, 101, 1, 1, 2000.00, 500.00, 3500.00, 3001, 1001, 1);

-- --------------------------------------------------------

--
-- Table structure for table `stock`
--

CREATE TABLE `stock` (
  `memberNo` int(11) NOT NULL,
  `recordDate` date NOT NULL,
  `applicationID` int(11) NOT NULL,
  `shareCapital` decimal(12,2) DEFAULT 0.00,
  `feeCapital` decimal(12,2) DEFAULT 0.00,
  `fixedSaving` decimal(12,2) DEFAULT 0.00,
  `memberSavings` decimal(12,2) DEFAULT 0.00,
  `memberFund` decimal(12,2) DEFAULT 0.00
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `stock`
--

INSERT INTO `stock` (`memberNo`, `recordDate`, `applicationID`, `shareCapital`, `feeCapital`, `fixedSaving`, `memberSavings`, `memberFund`) VALUES
(101, '2025-01-15', 3001, 2000.00, 500.00, 1000.00, 3500.00, 3500.00),
(102, '2024-12-20', 3002, 1500.00, 300.00, 800.00, 6100.00, 6100.00);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `boardofdirector`
--
ALTER TABLE `boardofdirector`
  ADD PRIMARY KEY (`bodID`);

--
-- Indexes for table `kadaadmin`
--
ALTER TABLE `kadaadmin`
  ADD PRIMARY KEY (`adminID`);

--
-- Indexes for table `loan`
--
ALTER TABLE `loan`
  ADD PRIMARY KEY (`loanApplicationID`),
  ADD KEY `applicationID` (`applicationID`);

--
-- Indexes for table `membership`
--
ALTER TABLE `membership`
  ADD PRIMARY KEY (`applicationID`),
  ADD UNIQUE KEY `email` (`email`),
  ADD UNIQUE KEY `icNo` (`icNo`),
  ADD UNIQUE KEY `phoneNo` (`phoneNo`);

--
-- Indexes for table `reporthub`
--
ALTER TABLE `reporthub`
  ADD PRIMARY KEY (`Month`,`Year`),
  ADD KEY `adminID` (`adminID`),
  ADD KEY `bodID` (`bodID`),
  ADD KEY `memberNo` (`memberNo`),
  ADD KEY `fk_applicationID` (`applicationID`),
  ADD KEY `fk_loanApplicationID` (`loanApplicationID`);

--
-- Indexes for table `stock`
--
ALTER TABLE `stock`
  ADD PRIMARY KEY (`memberNo`,`recordDate`),
  ADD KEY `applicationID` (`applicationID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `loan`
--
ALTER TABLE `loan`
  ADD CONSTRAINT `loan_ibfk_1` FOREIGN KEY (`applicationID`) REFERENCES `membership` (`applicationID`);

--
-- Constraints for table `reporthub`
--
ALTER TABLE `reporthub`
  ADD CONSTRAINT `fk_applicationID` FOREIGN KEY (`applicationID`) REFERENCES `membership` (`applicationID`),
  ADD CONSTRAINT `fk_loanApplicationID` FOREIGN KEY (`loanApplicationID`) REFERENCES `loan` (`loanApplicationID`),
  ADD CONSTRAINT `reporthub_ibfk_1` FOREIGN KEY (`adminID`) REFERENCES `kadaadmin` (`adminID`),
  ADD CONSTRAINT `reporthub_ibfk_2` FOREIGN KEY (`bodID`) REFERENCES `boardofdirector` (`bodID`),
  ADD CONSTRAINT `reporthub_ibfk_3` FOREIGN KEY (`memberNo`) REFERENCES `stock` (`memberNo`);

--
-- Constraints for table `stock`
--
ALTER TABLE `stock`
  ADD CONSTRAINT `stock_ibfk_1` FOREIGN KEY (`applicationID`) REFERENCES `membership` (`applicationID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
